#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import sys
import glob
import re
import string
from jinja2 import Template, Environment, FileSystemLoader

env = Environment(loader=FileSystemLoader('./', encoding='utf8'))

if len(sys.argv) != 5:
	print("ERROR: generate.py <tpl_file> <ros_json_file> <dep_lists> <varray_size.json>")
	sys.exit()

tpl_file=sys.argv[1] 
ros_json_file=sys.argv[2]
dep_lists=sys.argv[3]
varray_json_file=sys.argv[4]



tmp_str_array = ros_json_file.split(".")[1].split("/")
pkg_name = tmp_str_array[len(tmp_str_array) - 2]
msg_type_name = tmp_str_array[len(tmp_str_array) - 1]

class RosMessageContainer:
    pass

class RosMessage:
    pass

def to_conv(name):
	tmp = name.replace("int", "Int").replace("uInt", "UInt").replace("float", "Float").replace("string", "String").replace("bool", "Bool")
	return re.sub(r'\[.*\]', "Array", tmp)

def is_primitive(name):
	if (name == 'int8'):
		return True
	elif (name == 'uint8'):
		return True
	elif (name == 'byte'):
		return True
	elif (name == 'char'):
		return True
	elif (name == 'int16'):
		return True
	elif (name == 'uint16'):
		return True
	elif (name == 'int32'):
		return True
	elif (name == 'uint32'):
		return True
	elif (name == 'int64'):
		return True
	elif (name == 'uint64'):
		return True
	elif (name == 'float32'):
		return True
	elif (name == 'float64'):
		return True
	elif (name == 'bool'):
		return True
	else:
		return False

def is_string(name):
	if (name == 'string'):
		return True
	else:
		return False

def is_array(name):
	if (name.find('[') > 0):
		return True
	else:
		return False

def is_primitive_array(name):
	if (is_array(name) and is_primitive(get_array_type(name))):
		return True
	else:
		return False

def is_string_array(name):
	if (is_array(name) and is_string(get_array_type(name))):
		return True
	else:
		return False

def get_array_type(name):
	tmp = name.split('[')
	return get_msg_type(tmp[0].strip())

def get_struct_array_type(name):
    """
    配列型の構造体要素の型を返しますが、パッケージ名を保持します。
    """
    # 配列型の基本型を抽出
    base_type = name.split('[')[0].strip()
    return base_type

def get_array_size(mem_name, name):
    global container
    pkg = container.pkg_name
    type = container.msg_type_name
    tmp = name.split('[')[1]
    
    if tmp.split(']')[0] != '':
        return tmp.split(']')[0]
    else:
        # pkgが存在しない場合
        if pkg not in container.varry_json_data or container.varry_json_data[pkg] is None:
            return None
        
        # typeが存在しない場合
        if type not in container.varry_json_data[pkg] or container.varry_json_data[pkg][type] is None:
            return None
        
        # mem_nameが存在しない場合
        if mem_name not in container.varry_json_data[pkg][type] or container.varry_json_data[pkg][type][mem_name] is None:
            return None
        else:
            return container.varry_json_data[pkg][type][mem_name]

def get_type(name):
	if (is_array(name)):
		return get_array_type(name)
	else:
		return name

def get_msg_type(name):
	if (name.find('/') > 0):
		tmp = name.split('/')[1]
	else:
		tmp = name
	if (tmp == 'time'):
		return 'Time'
	else:
		return tmp

def get_msg_pkg(name):
	if (name.find('/') > 0):
		return name.split('/')[0]
	else:
		return pkg_name


def convert_snake(str):
    if str == "TFMessage":
        return "tf_message"
    s0 = str[0].lower()
    s1n = str[1:]
    cs1n = re.sub("([A-Z])", lambda x:"_" + x.group(1).lower(), s1n)
    return s0 + cs1n

def get_csharp_type(name):
    type_map = {
		"byte": "byte",
		"char": "byte",
        "int8": "sbyte",
        "uint8": "byte",
        "int16": "short",
        "uint16": "ushort",
        "int32": "int",
        "uint32": "uint",
        "int64": "long",
        "uint64": "ulong",
        "float32": "float",
        "float64": "double",
        "bool": "bool",
        "string": "string"
    }
    return type_map.get(name, name)

global container
container = RosMessageContainer()
container.convert_snake = convert_snake
container.to_conv = to_conv
container.get_type = get_type
container.get_array_type = get_array_type
container.is_array = is_array
container.is_primitive = is_primitive
container.is_primitive_array = is_primitive_array
container.is_string_array = is_string_array
container.get_msg_type = get_msg_type
container.get_msg_pkg = get_msg_pkg
container.pkg_name = pkg_name
container.msg_type_name = msg_type_name
container.get_array_size = get_array_size
container.get_struct_array_type = get_struct_array_type
container.is_string = is_string
container.get_csharp_type = get_csharp_type

container.includes = []
for line in open(dep_lists, 'r'):
	pkg_name = line.split("/")[0]
	msg_name = line.split("/")[1].strip()
	container.includes.append(pkg_name + "/pdu_ctype_" + msg_name + ".h")

container.csharp_includes = []
for line in open(dep_lists, 'r'):
	pkg_name = line.split("/")[0]
	msg_name = line.split("/")[1].strip()
	if pkg_name != container.pkg_name and container.csharp_includes.count(pkg_name) == 0:
		container.csharp_includes.append(pkg_name)

container.cpp_includes = []
for line in open(dep_lists, 'r'):
	pkg_name = line.split("/")[0]
	msg_name = line.split("/")[1].strip()
	container.cpp_includes.append(pkg_name + "/pdu_cpptype_" + msg_name + ".hpp")

container.conv_includes = []
for line in open(dep_lists, 'r'):
	pkg_name = line.split("/")[0]
	msg_name = line.split("/")[1].strip()
	container.conv_includes.append(pkg_name + "/pdu_ctype_conv_" + msg_name + ".hpp")

container.conv_cpp_includes = []
for line in open(dep_lists, 'r'):
	pkg_name = line.split("/")[0]
	msg_name = line.split("/")[1].strip()
	container.conv_cpp_includes.append(pkg_name + "/pdu_cpptype_conv_" + msg_name + ".hpp")

tmp_file = open(ros_json_file)
container.json_data = json.load(tmp_file)

tmp_varry_file = open(varray_json_file)
container.varry_json_data = json.load(tmp_varry_file)


tpl = env.get_template(tpl_file)
out = tpl.render({'container':container})

print(out)

