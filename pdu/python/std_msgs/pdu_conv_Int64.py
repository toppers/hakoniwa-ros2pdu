
import struct
from .pdu_pytype_Int64 import Int64
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Int64(pdu_bytes: bytes) -> Int64:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Int64()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: data (single)
    
    
    py_obj.data = struct.unpack_from('<q', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_Int64(py_obj: Int64) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: data (single)
    
    
    struct.pack_into('<q', base_buffer, 0, py_obj.data)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
