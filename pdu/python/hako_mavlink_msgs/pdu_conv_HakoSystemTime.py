
import struct
from .pdu_pytype_HakoSystemTime import HakoSystemTime
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoSystemTime(pdu_bytes: bytes) -> HakoSystemTime:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoSystemTime()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_unix_usec (single)
    
    
    py_obj.time_unix_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    # Processing: time_boot_ms (single)
    
    
    py_obj.time_boot_ms = struct.unpack_from('<Q', base_data, 8)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoSystemTime(py_obj: HakoSystemTime) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 16
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_unix_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_unix_usec)
    
    
    
    # Processing: time_boot_ms (single)
    
    
    struct.pack_into('<Q', base_buffer, 8, py_obj.time_boot_ms)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
