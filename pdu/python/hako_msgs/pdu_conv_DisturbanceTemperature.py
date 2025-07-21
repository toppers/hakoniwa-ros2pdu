
import struct
from .pdu_pytype_DisturbanceTemperature import DisturbanceTemperature
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_DisturbanceTemperature(pdu_bytes: bytes) -> DisturbanceTemperature:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = DisturbanceTemperature()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: value (single)
    
    
    py_obj.value = struct.unpack_from('<d', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_DisturbanceTemperature(py_obj: DisturbanceTemperature) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: value (single)
    
    
    struct.pack_into('<d', base_buffer, 0, py_obj.value)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
