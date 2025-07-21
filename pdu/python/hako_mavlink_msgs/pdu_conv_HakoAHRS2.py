
import struct
from .pdu_pytype_HakoAHRS2 import HakoAHRS2
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoAHRS2(pdu_bytes: bytes) -> HakoAHRS2:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoAHRS2()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: roll (single)
    
    
    py_obj.roll = struct.unpack_from('<f', base_data, 0)[0]
    
    
    
    # Processing: pitch (single)
    
    
    py_obj.pitch = struct.unpack_from('<f', base_data, 4)[0]
    
    
    
    # Processing: yaw (single)
    
    
    py_obj.yaw = struct.unpack_from('<f', base_data, 8)[0]
    
    
    
    # Processing: altitude (single)
    
    
    py_obj.altitude = struct.unpack_from('<f', base_data, 12)[0]
    
    
    
    # Processing: lat (single)
    
    
    py_obj.lat = struct.unpack_from('<i', base_data, 16)[0]
    
    
    
    # Processing: lng (single)
    
    
    py_obj.lng = struct.unpack_from('<i', base_data, 20)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoAHRS2(py_obj: HakoAHRS2) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 24
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: roll (single)
    
    
    struct.pack_into('<f', base_buffer, 0, py_obj.roll)
    
    
    
    # Processing: pitch (single)
    
    
    struct.pack_into('<f', base_buffer, 4, py_obj.pitch)
    
    
    
    # Processing: yaw (single)
    
    
    struct.pack_into('<f', base_buffer, 8, py_obj.yaw)
    
    
    
    # Processing: altitude (single)
    
    
    struct.pack_into('<f', base_buffer, 12, py_obj.altitude)
    
    
    
    # Processing: lat (single)
    
    
    struct.pack_into('<i', base_buffer, 16, py_obj.lat)
    
    
    
    # Processing: lng (single)
    
    
    struct.pack_into('<i', base_buffer, 20, py_obj.lng)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
