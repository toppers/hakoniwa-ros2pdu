
import struct
from .pdu_pytype_Ev3PduColorSensor import Ev3PduColorSensor
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Ev3PduColorSensor(pdu_bytes: bytes) -> Ev3PduColorSensor:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Ev3PduColorSensor()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: color (single)
    
    
    py_obj.color = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: reflect (single)
    
    
    py_obj.reflect = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: rgb_r (single)
    
    
    py_obj.rgb_r = struct.unpack_from('<I', base_data, 8)[0]
    
    
    
    # Processing: rgb_g (single)
    
    
    py_obj.rgb_g = struct.unpack_from('<I', base_data, 12)[0]
    
    
    
    # Processing: rgb_b (single)
    
    
    py_obj.rgb_b = struct.unpack_from('<I', base_data, 16)[0]
    
    
    
    return py_obj

def py_to_pdu_Ev3PduColorSensor(py_obj: Ev3PduColorSensor) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 20
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: color (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.color)
    
    
    
    # Processing: reflect (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.reflect)
    
    
    
    # Processing: rgb_r (single)
    
    
    struct.pack_into('<I', base_buffer, 8, py_obj.rgb_r)
    
    
    
    # Processing: rgb_g (single)
    
    
    struct.pack_into('<I', base_buffer, 12, py_obj.rgb_g)
    
    
    
    # Processing: rgb_b (single)
    
    
    struct.pack_into('<I', base_buffer, 16, py_obj.rgb_b)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
