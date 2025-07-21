
import struct
from .pdu_pytype_HakoATTITUDE import HakoATTITUDE
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoATTITUDE(pdu_bytes: bytes) -> HakoATTITUDE:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoATTITUDE()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_boot_ms (single)
    
    
    py_obj.time_boot_ms = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: roll (single)
    
    
    py_obj.roll = struct.unpack_from('<f', base_data, 4)[0]
    
    
    
    # Processing: pitch (single)
    
    
    py_obj.pitch = struct.unpack_from('<f', base_data, 8)[0]
    
    
    
    # Processing: yaw (single)
    
    
    py_obj.yaw = struct.unpack_from('<f', base_data, 12)[0]
    
    
    
    # Processing: rollspeed (single)
    
    
    py_obj.rollspeed = struct.unpack_from('<f', base_data, 16)[0]
    
    
    
    # Processing: pitchspeed (single)
    
    
    py_obj.pitchspeed = struct.unpack_from('<f', base_data, 20)[0]
    
    
    
    # Processing: yawspeed (single)
    
    
    py_obj.yawspeed = struct.unpack_from('<f', base_data, 24)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoATTITUDE(py_obj: HakoATTITUDE) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 28
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_boot_ms (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.time_boot_ms)
    
    
    
    # Processing: roll (single)
    
    
    struct.pack_into('<f', base_buffer, 4, py_obj.roll)
    
    
    
    # Processing: pitch (single)
    
    
    struct.pack_into('<f', base_buffer, 8, py_obj.pitch)
    
    
    
    # Processing: yaw (single)
    
    
    struct.pack_into('<f', base_buffer, 12, py_obj.yaw)
    
    
    
    # Processing: rollspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 16, py_obj.rollspeed)
    
    
    
    # Processing: pitchspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 20, py_obj.pitchspeed)
    
    
    
    # Processing: yawspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 24, py_obj.yawspeed)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
