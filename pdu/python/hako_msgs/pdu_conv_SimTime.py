
import struct
from .pdu_pytype_SimTime import SimTime
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_SimTime(pdu_bytes: bytes) -> SimTime:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = SimTime()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_SimTime(py_obj: SimTime) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_usec)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
