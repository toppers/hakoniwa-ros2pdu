import os
import re
from pathlib import Path
import jinja2
from collections import OrderedDict 

def _collect_dependencies(pkg_msg, message_cache, root_pkg,
                          visited,  # set[str]
                          includes, csharp_includes,
                          cpp_includes, conv_includes, conv_cpp_includes):
    if pkg_msg in visited:
        return
    visited.add(pkg_msg)

    msg_def = message_cache[pkg_msg]
    for field in msg_def.get('fields', []):
        ftype = field['type']
        if is_primitive(ftype) or is_string(ftype):
            continue

        base = get_array_type(ftype)
        dep_pkg_msg = f"{msg_def['package']}/{base}" if '/' not in base else base
        if dep_pkg_msg not in message_cache:
            continue                        # キャッシュに無ければ無視

        dep_pkg, dep_msg = dep_pkg_msg.split('/')

        # ───── include 群に追加（順序保持したいので OrderedDict を使う）─────
        includes[f"{dep_pkg}/pdu_ctype_{dep_msg}.h"] = None
        cpp_includes[f"{dep_pkg}/pdu_cpptype_{dep_msg}.hpp"] = None
        conv_includes[f"{dep_pkg}/pdu_ctype_conv_{dep_msg}.hpp"] = None
        conv_cpp_includes[f"{dep_pkg}/pdu_cpptype_conv_{dep_msg}.hpp"] = None
        if dep_pkg != root_pkg:
            csharp_includes[dep_pkg] = None

        # ───── さらに再帰 ─────
        _collect_dependencies(dep_pkg_msg, message_cache, root_pkg,
                              visited, includes, csharp_includes,
                              cpp_includes, conv_includes, conv_cpp_includes)
# --- テンプレートヘルパー関数群 (generate.pyの挙動を完全に模倣) ---

ROS_PRIMITIVE_TYPES_FOR_TEMPLATE = [
    'bool', 'byte', 'char', 'float32', 'float64', 'int8', 'uint8',
    'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64'
]

def get_array_type(name):
    return name.split('[', 1)[0].strip()

def is_primitive(name):
    return name in ROS_PRIMITIVE_TYPES_FOR_TEMPLATE

def is_string(name):
	if (name == 'string'):
		return True
	else:
		return False

def is_array(name):
    return '[' in name

def is_primitive_array(name):
    return is_array(name) and is_primitive(get_array_type(name))

def is_string_array(name):
    return is_array(name) and is_string(get_array_type(name))

def get_struct_array_type(name):
    return name.split('[', 1)[0].strip()

def get_type(name):
    if is_array(name):
        return get_array_type(name)
    return name

def get_msg_type(name):
    name = get_array_type(name)
    if '/' in name:
        tmp = name.split('/')[1]
    else:
        tmp = name
    if tmp == 'time':
        return 'Time'
    return tmp

def get_msg_pkg(name, default_pkg):
    name = get_array_type(name)
    if '/' in name:
        return name.split('/')[0]
    return default_pkg

def convert_snake(name):
    if name == "TFMessage":
        return "tf_message"
    s0 = name[0].lower()
    s1n = name[1:]
    cs1n = re.sub("([A-Z])", lambda x: "_" + x.group(1).lower(), s1n)
    return s0 + cs1n

def get_csharp_type(name):
    type_map = {
        "byte": "byte", "char": "byte", "int8": "sbyte", "uint8": "byte",
        "int16": "short", "uint16": "ushort", "int32": "int", "uint32": "uint",
        "int64": "long", "uint64": "ulong", "float32": "float",
        "float64": "double", "bool": "bool", "string": "string"
    }
    return type_map.get(get_array_type(name), get_msg_type(name))

# --- CodeGenerator クラス ---

class CodeGenerator:
    def __init__(self, template_dir):
        self.template_dir = Path(template_dir)

    def _render_template(self, template_name, context):
        template_path = self.template_dir / template_name
        with open(template_path, 'r', encoding='utf-8') as f:
            template_str = f.read()
        env = jinja2.Environment(loader=jinja2.FileSystemLoader(self.template_dir, encoding='utf8'))
        tpl = env.get_template(template_name)
        return tpl.render(context)

    def _prepare_context(self, package_msg, message_cache, varray_size_def):
        msg_def = message_cache[package_msg]
        root_pkg = msg_def['package']
        msg_name = msg_def['message']

        includes          = OrderedDict()
        csharp_includes   = OrderedDict()
        cpp_includes      = OrderedDict()
        conv_includes     = OrderedDict()
        conv_cpp_includes = OrderedDict()

        _collect_dependencies(package_msg, message_cache, root_pkg,
                          visited=set(),
                          includes=includes,
                          csharp_includes=csharp_includes,
                          cpp_includes=cpp_includes,
                          conv_includes=conv_includes,
                          conv_cpp_includes=conv_cpp_includes)

        def get_array_size(mem_name, type_name_from_tpl):
            try:
                return varray_size_def[root_pkg][msg_name][mem_name]
            except KeyError:
                if '[' in type_name_from_tpl and ']' in type_name_from_tpl:
                    size_str = type_name_from_tpl.split('[', 1)[1].split(']', 1)[0]
                    if size_str:
                        return size_str
                return None

        container = {
            'json_data': msg_def, 'pkg_name': root_pkg, 'msg_type_name': msg_name,
            'includes': sorted(includes), 
            'csharp_includes': sorted(csharp_includes), 
            'cpp_includes': sorted(cpp_includes),
            'conv_includes': sorted(conv_includes), 
            'conv_cpp_includes': sorted(conv_cpp_includes),
            'is_primitive': is_primitive, 'is_string': is_string, 'is_array': is_array,
            'is_primitive_array': is_primitive_array, 'is_string_array': is_string_array,
            'get_array_type': get_array_type, 'get_struct_array_type': get_struct_array_type,
            'get_type': get_type, 'get_msg_type': get_msg_type,
            'get_msg_pkg': lambda name: get_msg_pkg(name, root_pkg),
            'get_array_size': get_array_size, 'convert_snake': convert_snake,
            'get_csharp_type': get_csharp_type
        }
        return {'container': container}

    def _generate_file(self, context, template_name, output_dir, file_pattern, description):
        content = self._render_template(template_name, context)
        if not content.endswith('\n'):
            content += '\n'
        if not content.strip():
            return

        pkg_name = context['container']['pkg_name']
        msg_name = context['container']['msg_type_name']
        output_path = Path(output_dir) / pkg_name
        output_path.mkdir(parents=True, exist_ok=True)
        file_path = output_path / file_pattern.format(msg_name=msg_name)
        with open(file_path, 'w', encoding='utf-8', newline='\n') as f:
            f.write(content)
        print(f"Generated {description}: {file_path}")

    def generate_all(self, message_cache, varray_size_def, output_root_dir):
        types_dir = Path(output_root_dir) / 'types'
        csharp_dir = Path(output_root_dir) / 'csharp'

        for package_msg in message_cache.keys():
            context = self._prepare_context(package_msg, message_cache, varray_size_def)
            self._generate_file(context, 'pdu_ctypes_h.tpl', types_dir, "pdu_ctype_{msg_name}.h", "C header")
            self._generate_file(context, 'pdu_csharp_class.tpl', csharp_dir, "{msg_name}.cs", "C# class")
            self._generate_file(context, 'pdu_cpptypes_hpp.tpl', types_dir, "pdu_cpptype_{msg_name}.hpp", "C++ type header")
            self._generate_file(context, 'pdu_ctypes_conv_cpp.tpl', types_dir, "pdu_ctype_conv_{msg_name}.hpp", "C->C++ conv header")
            self._generate_file(context, 'pdu_cpptypes_conv_cpp.tpl', types_dir, "pdu_cpptype_conv_{msg_name}.hpp", "C++->C conv header")