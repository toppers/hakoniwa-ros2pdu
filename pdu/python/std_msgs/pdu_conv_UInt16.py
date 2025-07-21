
import struct
from .pdu_pytype_UInt16 import UInt16
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_UInt16(pdu_bytes: bytes) -> UInt16:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = UInt16()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: data (single)
    
    
    py_obj.data = struct.unpack_from('<H', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_UInt16(py_obj: UInt16) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 2
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: data (single)
    
    
    struct.pack_into('<H', base_buffer, 0, py_obj.data)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
