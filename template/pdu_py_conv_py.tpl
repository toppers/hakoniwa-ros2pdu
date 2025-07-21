{# pdu/python/pdu_conv_{msg_name}.py を生成するためのテンプレート #}
import struct
from .pdu_pytype_{{ container.msg_type_name }} import {{ container.class_name }}
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
{% for imp in container.py_conv_imports -%}
from ..{{ imp.dep_pkg }}.{{ imp.file }} import *
{% endfor %}


def pdu_to_py_{{ container.msg_type_name }}(binary_data: bytes) -> {{ container.class_name }}:
    py_obj = {{ container.class_name }}()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_{{ container.msg_type_name }}(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_{{ container.msg_type_name }}(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: {{ container.class_name }}, base_off):
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
    py_obj.{{ item.member_name }} = binary_io.binTovalue(type, bin)
    {% elif item.array_type == 'array' %}
    array_value = binary_io.readBinary(binary_data, base_off + {{ item.offset }}, {{ item.size }})
    py_obj.{{ item.member_name }} = binary_io.binToArrayValues(type, array_value)
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
    {% else -%}
    {% endif -%}
{% endif -%}
{% endfor %}
    return py_obj