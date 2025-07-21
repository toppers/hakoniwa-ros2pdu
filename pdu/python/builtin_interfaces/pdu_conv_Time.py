
import struct
from .pdu_pytype_Time import Time
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Time(pdu_bytes: bytes) -> Time:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Time()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: sec (single)
    
    
        
    py_obj.sec = struct.unpack_from('<i', base_data, 0)[0]
        
    
    
    
    # Processing: nanosec (single)
    
    
        
    py_obj.nanosec = struct.unpack_from('<I', base_data, 4)[0]
        
    
    
    
    return py_obj

def py_to_pdu_Time(py_obj: Time) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: sec (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.sec)
    
    
    
    # Processing: nanosec (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.nanosec)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
