{# pdu/python/pdu_conv_{msg_name}.py を生成するためのテンプレート #}
import struct
from .pdu_pytype_{{ container.msg_type_name }} import {{ container.class_name }}
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

{% for imp in container.py_conv_imports %}
from .{{ imp.file }} import pdu_to_py_{{ imp.class_name }}, py_to_pdu_{{ imp.class_name }}
{% endfor %}

def pdu_to_py_{{ container.msg_type_name }}(pdu_bytes: bytes) -> {{ container.class_name }}:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = {{ container.class_name }}()

    # 各フィールドをオフセット情報に基づいてデコード
    {% for item in container.offset_data %}
    # Processing: {{ item.member_name }} ({{ item.array_type }})
    {% if item.array_type == 'single' %}
    {%   if item.data_type == 'primitive' %}
    py_obj.{{ item.member_name }} = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', base_data, {{ item.offset }})[0]
    {%   elif item.data_type == 'string' %}
    # 固定長文字列
    end = base_data.find(b'\0', {{ item.offset }})
    py_obj.{{ item.member_name }} = base_data[{{ item.offset }}:end].decode('utf-8')
    {%   else %}
    # ネストされた構造体
    nested_base_data = base_data[{{ item.offset }}:{{ item.offset + item.size }}]
    # ネストされた構造体のデシリアライズには、完全なPDUバイト列を再構築して渡す
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.{{ item.member_name }} = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
    {%   endif %}
    {% elif item.array_type == 'array' %}
    # 固定長配列
    py_obj.{{ item.member_name }} = []
    element_size = {{ item.size // item.array_len }}
    for i in range({{ item.array_len }}):
        element_offset = {{ item.offset }} + i * element_size
    {%   if item.data_type == 'primitive' %}
        val = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', base_data, element_offset)[0]
        py_obj.{{ item.member_name }}.append(val)
    {%   elif item.data_type == 'string' %}
        end = base_data.find(b'\0', element_offset)
        val = base_data[element_offset:end].decode('utf-8')
        py_obj.{{ item.member_name }}.append(val)
    {%   else %}
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
        py_obj.{{ item.member_name }}.append(val)
    {%   endif %}
    {% elif item.array_type == 'varray' %}
    # 可変長配列
    ref_offset = {{ item.offset }}
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.{{ item.member_name }} = []
    element_size = {{ item.size }} # varrayの場合、sizeは要素1つのサイズ
    for i in range(array_len):
        element_heap_offset = heap_offset + i * element_size
    {%   if item.data_type == 'primitive' %}
        val = struct.unpack_from('{{ container.get_struct_format(item.type_name) }}', heap_data, element_heap_offset)[0]
        py_obj.{{ item.member_name }}.append(val)
    {%   elif item.data_type == 'string' %}
        # 可変長文字列配列は、オフセットの配列としてヒープに格納されている
        str_ref_format = '>i' # ヒープ内のオフセット
        str_offset_in_heap = struct.unpack_from(str_ref_format, heap_data, element_heap_offset)[0]
        end = heap_data.find(b'\0', str_offset_in_heap)
        val = heap_data[str_offset_in_heap:end].decode('utf-8')
        py_obj.{{ item.member_name }}.append(val)
    {%   else %}
        # 可変長構造体配列
        nested_pdu_bytes = heap_data[element_heap_offset:]
        val = pdu_to_py_{{ container.get_msg_type(item.type_name) }}(nested_pdu_bytes)
        py_obj.{{ item.member_name }}.append(val)
    {%   endif %}
    {% endif %}
    {% endfor %}
    return py_obj

def py_to_pdu_{{ container.msg_type_name }}(py_obj: {{ container.class_name }}) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    # BaseDataのサイズを計算（オフセット情報の最大値 + そのフィールドのサイズ）
    base_data_size = {{ container.get_base_data_size() }}
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    # 各フィールドをオフセット情報に基づいてシリアライズ
    {% for item in container.offset_data %}
    # Processing: {{ item.member_name }} ({{ item.array_type }})
    {% if item.array_type == 'single' %}
    {%   if item.data_type == 'primitive' %}
    struct.pack_into('{{ container.get_struct_format(item.type_name) }}', base_buffer, {{ item.offset }}, py_obj.{{ item.member_name }})
    {%   elif item.data_type == 'string' %}
    str_bytes = py_obj.{{ item.member_name }}.encode('utf-8')
    # NULL終端文字を追加し、固定長サイズに切り詰めるか、パディングする
    padded_str = (str_bytes + b'\0').ljust({{ item.size }}, b'\0')[:{{ item.size }}]
    base_buffer[{{ item.offset }}:{{ item.offset + item.size }}] = padded_str
    {%   else %}
    # ネストされた構造体
    nested_pdu_bytes = py_to_pdu_{{ container.get_msg_type(item.type_name) }}(py_obj.{{ item.member_name }})
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[{{ item.offset }}:{{ item.offset + item.size }}] = nested_base_data
    # ネストされたヒープのデータを現在のヒープに追加（オフセット調整が必要）
    # TODO: ネストされたヒープの正しい処理
    {%   endif %}
    {% elif item.array_type == 'array' %}
    # 固定長配列
    element_size = {{ item.size // item.array_len }}
    for i, element in enumerate(py_obj.{{ item.member_name }}):
        element_offset = {{ item.offset }} + i * element_size
    {%   if item.data_type == 'primitive' %}
        struct.pack_into('{{ container.get_struct_format(item.type_name) }}', base_buffer, element_offset, element)
    {%   else %}
        # TODO: 固定長配列の構造体・文字列
        pass
    {%   endif %}
    {% elif item.array_type == 'varray' %}
    # 可変長配列
    array_len = len(py_obj.{{ item.member_name }})
    element_size = {{ item.size }}
    
    # ヒープに実データを書き込む
    heap_elements = bytearray()
    for element in py_obj.{{ item.member_name }}:
    {%   if item.data_type == 'primitive' %}
        heap_elements += struct.pack('{{ container.get_struct_format(item.type_name) }}', element)
    {%   else %}
        # TODO: 可変長配列の構造体・文字列
        pass
    {%   endif %}
    heap_offset = heap.allocate(bytes(heap_elements))

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, {{ item.offset }}, array_len, heap_offset)
    {% endif %}
    {% endfor %}

    return create_pdu(bytes(base_buffer), heap.get_total_size(), heap.copy_to_pdu)