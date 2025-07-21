
import struct
from .pdu_pytype_SimpleVarray import SimpleVarray
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_SimpleVarray(pdu_bytes: bytes) -> SimpleVarray:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = SimpleVarray()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: data (varray)
    
    ref_offset = 0
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 1
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<b', heap_data, current_heap_offset)[0]
        py_obj.data.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: fixed_array (array)
    
    py_obj.fixed_array = []
    element_size = 1
    for i in range(10):
        element_offset = 8 + i * element_size
    
        val = struct.unpack_from('<b', base_data, element_offset)[0]
        py_obj.fixed_array.append(val)
    
    
    
    # Processing: p_mem1 (single)
    
    
    py_obj.p_mem1 = struct.unpack_from('<i', base_data, 20)[0]
    
    
    
    return py_obj

def py_to_pdu_SimpleVarray(py_obj: SimpleVarray) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 24
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.data:
        elements_heap_bytes += struct.pack('<b', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 0, array_len, heap_offset)
    
    
    # Processing: fixed_array (array)
    
    element_size = 1
    for i, element in enumerate(py_obj.fixed_array):
        if i >= 10: break
        element_offset = 8 + i * element_size
    
        struct.pack_into('<b', base_buffer, element_offset, element)
    
    
    
    # Processing: p_mem1 (single)
    
    
    struct.pack_into('<i', base_buffer, 20, py_obj.p_mem1)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
