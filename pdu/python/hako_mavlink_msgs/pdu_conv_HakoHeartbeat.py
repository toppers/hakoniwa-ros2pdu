
import struct
from .pdu_pytype_HakoHeartbeat import HakoHeartbeat
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoHeartbeat(pdu_bytes: bytes) -> HakoHeartbeat:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoHeartbeat()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: type (single)
    
    
    py_obj.type = struct.unpack_from('<B', base_data, 0)[0]
    
    
    
    # Processing: autopilot (single)
    
    
    py_obj.autopilot = struct.unpack_from('<B', base_data, 1)[0]
    
    
    
    # Processing: base_mode (single)
    
    
    py_obj.base_mode = struct.unpack_from('<B', base_data, 2)[0]
    
    
    
    # Processing: custom_mode (single)
    
    
    py_obj.custom_mode = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: system_status (single)
    
    
    py_obj.system_status = struct.unpack_from('<B', base_data, 8)[0]
    
    
    
    # Processing: mavlink_version (single)
    
    
    py_obj.mavlink_version = struct.unpack_from('<B', base_data, 9)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoHeartbeat(py_obj: HakoHeartbeat) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 10
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: type (single)
    
    
    struct.pack_into('<B', base_buffer, 0, py_obj.type)
    
    
    
    # Processing: autopilot (single)
    
    
    struct.pack_into('<B', base_buffer, 1, py_obj.autopilot)
    
    
    
    # Processing: base_mode (single)
    
    
    struct.pack_into('<B', base_buffer, 2, py_obj.base_mode)
    
    
    
    # Processing: custom_mode (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.custom_mode)
    
    
    
    # Processing: system_status (single)
    
    
    struct.pack_into('<B', base_buffer, 8, py_obj.system_status)
    
    
    
    # Processing: mavlink_version (single)
    
    
    struct.pack_into('<B', base_buffer, 9, py_obj.mavlink_version)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
