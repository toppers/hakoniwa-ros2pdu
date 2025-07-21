
import struct
from .pdu_pytype_Int8MultiArray import Int8MultiArray
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_MultiArrayLayout import pdu_to_py_, py_to_pdu_


def pdu_to_py_Int8MultiArray(pdu_bytes: bytes) -> Int8MultiArray:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Int8MultiArray()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: layout (single)
    
    
    nested_base_data = base_data[0:12]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.layout = pdu_to_py_MultiArrayLayout(nested_pdu_bytes)
    
    
    
    # Processing: data (varray)
    
    ref_offset = 12
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 1
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<b', heap_data, current_heap_offset)[0]
        py_obj.data.append(val)
        current_heap_offset += element_size
    
    
    
    return py_obj

def py_to_pdu_Int8MultiArray(py_obj: Int8MultiArray) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 13
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: layout (single)
    
    
    nested_pdu_bytes = py_to_pdu_MultiArrayLayout(py_obj.layout)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:12] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.data:
        elements_heap_bytes += struct.pack('<b', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 12, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
