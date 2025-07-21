{# pdu/python/pdu_conv_{msg_name}.py を生成するためのテンプレート #}
import struct
from .pdu_pytype_{{ container.msg_type_name }} import {{ container.class_name }}
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class
{% for imp in container.py_conv_imports %}
from ..{{ imp.dep_pkg }}.{{ imp.file }} import {{ imp.pdu_to_py_func }}, {{ imp.py_to_pdu_func }}
{% endfor %}

def pdu_to_py_{{ container.msg_type_name }}(pdu_bytes: bytes) -> {{ container.class_name }}:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = {{ container.class_name }}()

    # 各フィールドをオフセット情報に基づいてデコード
{%- for item in container.offset_data %}
    # array_type: {{ item.array_type }} 
    # data_type: {{ item.data_type }} 
    # member_name: {{ item.member_name }} 
    # type_name: {{ item.type_name }} 
    # offset: {{ item.offset }} size: {{ item.size }} 
    # array_len: {{ item.array_len }}
    {% if item.array_type == 'single' -%}
        {% if item.data_type == 'primitive' -%}
    py_obj.{{ item.member_name }} = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', base_data, {{ item.offset }})[0]
        {% elif item.data_type == 'string' %}
    end = base_data.find(b'\0', {{ item.offset }})
    py_obj.{{ item.member_name }} = base_data[{{ item.offset }}:end].decode('utf-8')
        {% else -%}
    nested_base_data = base_data[{{ item.offset }}:{{ item.offset + item.size }}]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.{{ item.member_name }} = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
        {% endif %}
    {% elif item.array_type == 'array' -%}
    py_obj.{{ item.member_name }} = []
    element_size = {{ item.size // item.array_len }}
    for i in range({{ item.array_len }}):
        element_offset = {{ item.offset }} + i * element_size
    {%   if item.data_type == 'primitive' -%}
        val = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', base_data, element_offset)[0]
        py_obj.{{ item.member_name }}.append(val)
    {%   elif item.data_type == 'string' -%}
        end = base_data.find(b'\0', element_offset)
        val = base_data[element_offset:end].decode('utf-8')
        py_obj.{{ item.member_name }}.append(val)
    {%   else -%}
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
        py_obj.{{ item.member_name }}.append(val)
    {%   endif -%}
    {% elif item.array_type == 'varray' -%}
    ref_offset = {{ item.offset }}
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.{{ item.member_name }} = []
    element_size = {{ item.size }}
    current_heap_offset = heap_offset
    for i in range(array_len):
    {%   if item.data_type == 'primitive' -%}
        val = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', heap_data, current_heap_offset)[0]
        py_obj.{{ item.member_name }}.append(val)
        current_heap_offset += element_size
    {%   elif item.data_type == 'string' -%}
        str_ref_format = '<i'
        str_offset_in_heap = struct.unpack_from(str_ref_format, heap_data, current_heap_offset)[0]
        end = heap_data.find(b'\0', heap_offset + str_offset_in_heap)
        val = heap_data[heap_offset + str_offset_in_heap:end].decode('utf-8')
        py_obj.{{ item.member_name }}.append(val)
        current_heap_offset += struct.calcsize(str_ref_format)
    {%   else -%}
        nested_pdu_bytes = heap_data[current_heap_offset:]
        val = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
        py_obj.{{ item.member_name }}.append(val)
        # Move offset by the total size of the nested PDU
        _m, _b, nested_heap = unpack_pdu(nested_pdu_bytes)
        current_heap_offset += _m['total_size']
    {%   endif -%}
    {% endif -%}
    {% endfor -%}
    return py_obj

def py_to_pdu_{{ container.msg_type_name }}(py_obj: {{ container.class_name }}) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = {{ container.get_base_data_size() }}
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    {% for item in container.offset_data %}
    # Processing: {{ item.member_name }} ({{ item.array_type }})
    {% if item.array_type == 'single' %}
    {%   if item.data_type == 'primitive' %}
    struct.pack_into('{{ container.get_struct_format(item.type_name) }}', base_buffer, {{ item.offset }}, py_obj.{{ item.member_name }})
    {%   elif item.data_type == 'string' %}
    str_bytes = py_obj.{{ item.member_name }}.encode('utf-8')
    padded_str = (str_bytes + b'\0').ljust({{ item.size }}, b'\0')[:{{ item.size }}]
    base_buffer[{{ item.offset }}:{{ item.offset + item.size }}] = padded_str
    {%   else %}
    nested_pdu_bytes = py_to_pdu_{{ container.get_msg_type(item.type_name) }}(py_obj.{{ item.member_name }})
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[{{ item.offset }}:{{ item.offset + item.size }}] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    {%   endif %}
    {% elif item.array_type == 'array' %}
    element_size = {{ item.size // item.array_len }}
    for i, element in enumerate(py_obj.{{ item.member_name }}):
        if i >= {{ item.array_len }}: break
        element_offset = {{ item.offset }} + i * element_size
    {%   if item.data_type == 'primitive' %}
        struct.pack_into('{{ container.get_struct_format(item.type_name) }}', base_buffer, element_offset, element)
    {%   elif item.data_type == 'string' %}
        str_bytes = element.encode('utf-8')
        padded_str = (str_bytes + b'\0').ljust(element_size, b'\0')[:element_size]
        base_buffer[element_offset : element_offset + element_size] = padded_str
    {%   else %}
        nested_pdu_bytes = py_to_pdu_{{ container.get_msg_type(item.type_name) }}(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    {%   endif %}
    {% elif item.array_type == 'varray' %}
    array_len = len(py_obj.{{ item.member_name }})
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    {%   if item.data_type == 'primitive' %}
    for element in py_obj.{{ item.member_name }}:
        elements_heap_bytes += struct.pack('{{ container.get_struct_format(item.type_name) }}', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    {%   elif item.data_type == 'string' %}
    string_data_heap = PduDynamicMemoryPython()
    offsets_list = []
    for element in py_obj.{{ item.member_name }}:
        str_bytes = element.encode('utf-8') + b'\0'
        offsets_list.append(string_data_heap.allocate(str_bytes))
    # オフセットのリスト自体もヒープに確保
    offsets_bytes = b''.join([struct.pack('<i', off) for off in offsets_list])
    # 文字列の実データをヒープに追加
    string_data_bytes = string_data_heap.get_bytes()
    # オフセットリストと文字列実データを結合してヒープに確保
    heap_offset = heap.allocate(offsets_bytes + string_data_bytes)
    {%   else %}
    # 構造体の可変長配列
    for element in py_obj.{{ item.member_name }}:
        nested_pdu_bytes = py_to_pdu_{{ container.get_msg_type(item.type_name) }}(element)
        elements_heap_bytes += nested_pdu_bytes
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    {%   endif %}

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, {{ item.offset }}, array_len, heap_offset)
    {% endif %}
    {% endfor %}

    return create_pdu(bytes(base_buffer), heap.get_bytes())