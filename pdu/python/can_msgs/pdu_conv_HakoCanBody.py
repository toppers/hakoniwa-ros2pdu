
import struct
from .pdu_pytype_HakoCanBody import HakoCanBody
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoCanBody(pdu_bytes: bytes) -> HakoCanBody:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoCanBody()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: data (array)
    
    py_obj.data = []
    element_size = 1
    for i in range(8):
        element_offset = 0 + i * element_size
    
        val = struct.unpack_from('<B', base_data, element_offset)[0]
        py_obj.data.append(val)
    
    
    
    return py_obj

def py_to_pdu_HakoCanBody(py_obj: HakoCanBody) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: data (array)
    
    element_size = 1
    for i, element in enumerate(py_obj.data):
        if i >= 8: break
        element_offset = 0 + i * element_size
    
        struct.pack_into('<B', base_buffer, element_offset, element)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
