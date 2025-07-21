
import struct
from .pdu_pytype_Int32 import Int32
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Int32(pdu_bytes: bytes) -> Int32:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Int32()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: data (single)
    
    
    py_obj.data = struct.unpack_from('<i', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_Int32(py_obj: Int32) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 4
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: data (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.data)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
