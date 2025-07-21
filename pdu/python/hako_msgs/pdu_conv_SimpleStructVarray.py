
import struct
from .pdu_pytype_SimpleStructVarray import SimpleStructVarray
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..hako_msgs.pdu_conv_SimpleVarray import pdu_to_py_, py_to_pdu_

from ..hako_msgs.pdu_conv_SimpleVarray import pdu_to_py_, py_to_pdu_


def pdu_to_py_SimpleStructVarray(pdu_bytes: bytes) -> SimpleStructVarray:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = SimpleStructVarray()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: aaa (single)
    
    
    py_obj.aaa = struct.unpack_from('<i', base_data, 0)[0]
    
    
    
    # Processing: fixed_str (array)
    
    py_obj.fixed_str = []
    element_size = 128
    for i in range(2):
        element_offset = 4 + i * element_size
    
        val = struct.unpack_from('<', base_data, element_offset)[0]
        py_obj.fixed_str.append(val)
    
    
    
    # Processing: varray_str (varray)
    
    ref_offset = 260
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.varray_str = []
    element_size = 128
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<', heap_data, current_heap_offset)[0]
        py_obj.varray_str.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: fixed_array (array)
    
    py_obj.fixed_array = []
    element_size = 24
    for i in range(5):
        element_offset = 268 + i * element_size
    
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_SimpleVarray(nested_pdu_bytes)
        py_obj.fixed_array.append(val)
    
    
    
    # Processing: data (varray)
    
    ref_offset = 388
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 24
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        nested_pdu_bytes = heap_data[current_heap_offset:]
        val = pdu_to_py_SimpleVarray(nested_pdu_bytes)
        py_obj.data.append(val)
        # Move offset by the total size of the nested PDU
        _m, _b, nested_heap = unpack_pdu(nested_pdu_bytes)
        current_heap_offset += _m['total_size']
    
    
    
    return py_obj

def py_to_pdu_SimpleStructVarray(py_obj: SimpleStructVarray) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 412
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: aaa (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.aaa)
    
    
    
    # Processing: fixed_str (array)
    
    element_size = 128
    for i, element in enumerate(py_obj.fixed_str):
        if i >= 2: break
        element_offset = 4 + i * element_size
    
        struct.pack_into('<', base_buffer, element_offset, element)
    
    
    
    # Processing: varray_str (varray)
    
    array_len = len(py_obj.varray_str)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.varray_str:
        elements_heap_bytes += struct.pack('<', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 260, array_len, heap_offset)
    
    
    # Processing: fixed_array (array)
    
    element_size = 24
    for i, element in enumerate(py_obj.fixed_array):
        if i >= 5: break
        element_offset = 268 + i * element_size
    
        nested_pdu_bytes = py_to_pdu_SimpleVarray(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    
    
    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    # 構造体の可変長配列
    for element in py_obj.data:
        nested_pdu_bytes = py_to_pdu_SimpleVarray(element)
        elements_heap_bytes += nested_pdu_bytes
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 388, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
