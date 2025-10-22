{# pdu/python/pdu_conv_{msg_name}.py を生成するためのテンプレート #}
import struct
from .pdu_pytype_{{ container.msg_type_name }} import {{ container.class_name }}
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
{% for imp in container.py_conv_imports -%}
from ..{{ imp.dep_pkg }}.{{ imp.file }} import *
{% endfor %}


def pdu_to_py_{{ container.msg_type_name }}(binary_data: bytearray) -> {{ container.class_name }}:
    py_obj = {{ container.class_name }}()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_{{ container.msg_type_name }}(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_{{ container.msg_type_name }}(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: {{ container.class_name }}, base_off: int):
{%- for item in container.offset_data %}
    # array_type: {{ item.array_type }} 
    # data_type: {{ item.data_type }} 
    # member_name: {{ item.member_name }} 
    # type_name: {{ item.type_name }} 
    # offset: {{ item.offset }} size: {{ item.size }} 
    # array_len: {{ item.array_len }}
{% if item.data_type == 'primitive' %}
    {% if item.array_type == 'single' %}
    bin = binary_io.readBinary(binary_data, base_off + {{ item.offset }}, {{ item.size }})
    py_obj.{{ item.member_name }} = binary_io.binTovalue("{{ item.type_name }}", bin)
    {% elif item.array_type == 'array' %}
    array_value = binary_io.readBinary(binary_data, base_off + {{ item.offset }}, {{ item.size }})
    py_obj.{{ item.member_name }} = binary_io.binToArrayValues("{{ item.type_name }}", array_value)
    {% else -%}
    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + {{ item.offset }}, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + {{ item.offset }} + 4, 4))
    one_elm_size = {{ item.size }} 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.{{ item.member_name }} = array_value
    {% endif -%}
{% else -%}
    {% if item.array_type == 'single' %}
    tmp_py_obj = {{ container.get_msg_type(item.type_name) }}()
    binary_read_recursive_{{ container.get_msg_type(item.type_name) }}(meta, binary_data, tmp_py_obj, base_off + {{ item.offset }})
    py_obj.{{ item.member_name }} = tmp_py_obj
    {% elif item.array_type == 'array' %}
    i = 0
    array_size = {{ item.array_len }}
    one_elm_size = int({{ item.size }} / array_size)
    array_value = []
    while i < array_size:
        tmp_py_obj = {{ container.get_msg_type(item.type_name) }}()
        binary_read_recursive_{{ container.get_msg_type(item.type_name) }}(meta, binary_data, tmp_py_obj, base_off + {{ item.offset }} + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.{{ item.member_name }} = array_value    
    {% else %}
    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + {{ item.offset }}, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + {{ item.offset }} + 4, 4))
    one_elm_size = {{ item.size }}
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = {{ container.get_msg_type(item.type_name) }}()
        binary_read_recursive_{{ container.get_msg_type(item.type_name) }}(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.{{ item.member_name }} = array_value    
    {% endif -%}
{% endif -%}
{% endfor %}
    return py_obj


def py_to_pdu_{{ container.msg_type_name }}(py_obj: {{ container.class_name }}) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_{{ container.get_msg_type(container.msg_type_name) }}(0, bw_container, base_allocator, py_obj)

    # メタデータの設定
    total_size = base_allocator.size() + bw_container.heap_allocator.size() + binary_io.PduMetaData.PDU_META_DATA_SIZE
    bw_container.meta.total_size = total_size
    bw_container.meta.heap_off = binary_io.PduMetaData.PDU_META_DATA_SIZE + base_allocator.size()

    # binary_data のサイズを total_size に調整
    if len(binary_data) < total_size:
        binary_data.extend(bytearray(total_size - len(binary_data)))
    elif len(binary_data) > total_size:
        del binary_data[total_size:]

    # メタデータをバッファにコピー
    binary_io.writeBinary(binary_data, 0, bw_container.meta.to_bytes())

    # 基本データをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.base_off, base_allocator.to_array())

    # ヒープデータをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.heap_off, bw_container.heap_allocator.to_array())

    return binary_data

def binary_write_recursive_{{ container.get_msg_type(container.msg_type_name) }}(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: {{ container.get_msg_type(container.msg_type_name) }}):
{%- for item in container.offset_data %}
    # array_type: {{ item.array_type }} 
    # data_type: {{ item.data_type }} 
    # member_name: {{ item.member_name }} 
    # type_name: {{ item.type_name }} 
    # offset: {{ item.offset }} size: {{ item.size }} 
    # array_len: {{ item.array_len }}
    type = "{{ container.get_msg_type(item.type_name)  }}"
    off = {{ item.offset }}
{% if item.data_type == 'primitive' %}
    {% if item.array_type == 'single' %}
    bin = binary_io.typeTobin(type, py_obj.{{ item.member_name }})
    bin = get_binary(type, bin, {{ item.size }})
    allocator.add(bin, expected_offset=parent_off + off)
    {% elif item.array_type == 'array' %}
    elm_size =  {{ item.size }} 
    array_size = int({{ (item.size / item.array_len) }})
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.{{ item.member_name }}, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    {% else -%}
    offset_from_heap = bw_container.heap_allocator.size()
    if allocator.is_heap:
        offset_from_heap += 8 # 8 bytes for array_size and offset
    array_size = len(py_obj.{{ item.member_name}})
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    binary = binary_io.typeTobin_array(type, py_obj.{{ item.member_name}}, {{ item.size }})
    bw_container.heap_allocator.add(binary, expected_offset=0)
    {% endif -%}
{% else -%}
    {% if item.array_type == 'single' %}
    binary_write_recursive_{{ container.get_msg_type(item.type_name) }}(parent_off + off, bw_container, allocator, py_obj.{{ item.member_name }})
    {% elif item.array_type == 'array' %}
    for i, elm in enumerate(py_obj.{{ item.member_name }}):
        elm_size = {{ item.size }}
        array_size = int({{ item.size / item.array_len }})
        one_elm_size = int(elm_size / array_size)
        binary_write_recursive_{{ container.get_msg_type(item.type_name) }}((parent_off + off + i * one_elm_size), bw_container, allocator, elm)
    {% else %}
    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.{{ item.member_name }})
    if allocator.is_heap:
        offset_from_heap += 8 # 8 bytes for array_size and offset
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    for i, elm in enumerate(py_obj.{{ item.member_name }}):
        one_elm_size =  {{ item.size }}
        binary_write_recursive_{{ container.get_msg_type(item.type_name) }}((parent_off + i * one_elm_size), bw_container, bw_container.heap_allocator, elm)
    {% endif -%}
{% endif -%}
{% endfor %}

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_{{ container.msg_type_name }} <read|write> [args...]")
        print(f"  read <input_binary_file> <output_json_file>")
        print(f"  write <input_json_file> <output_binary_file>")

    if len(sys.argv) < 2:
        print_usage()
        sys.exit(1)

    command = sys.argv[1]

    if command == "read":
        if len(sys.argv) != 4:
            print_usage()
            sys.exit(1)
        
        binary_filepath = sys.argv[2]
        output_json_filepath = sys.argv[3]

        with open(binary_filepath, "rb") as f:
            binary_data = bytearray(f.read())
        
        py_obj = pdu_to_py_{{ container.msg_type_name }}(binary_data)
        
        with open(output_json_filepath, "w") as f:
            f.write(py_obj.to_json())

    elif command == "write":
        if len(sys.argv) != 4:
            print_usage()
            sys.exit(1)

        input_json_filepath = sys.argv[2]
        output_binary_filepath = sys.argv[3]

        with open(input_json_filepath, "r") as f:
            json_str = f.read()
        
        py_obj = {{ container.class_name }}.from_json(json_str)
        
        binary_data = py_to_pdu_{{ container.msg_type_name }}(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)