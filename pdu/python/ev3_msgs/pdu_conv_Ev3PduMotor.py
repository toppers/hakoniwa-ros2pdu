
import struct
from .pdu_pytype_Ev3PduMotor import Ev3PduMotor
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Ev3PduMotor(pdu_bytes: bytes) -> Ev3PduMotor:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Ev3PduMotor()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: power (single)
    
    
    py_obj.power = struct.unpack_from('<i', base_data, 0)[0]
    
    
    
    # Processing: stop (single)
    
    
    py_obj.stop = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: reset_angle (single)
    
    
    py_obj.reset_angle = struct.unpack_from('<I', base_data, 8)[0]
    
    
    
    return py_obj

def py_to_pdu_Ev3PduMotor(py_obj: Ev3PduMotor) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 12
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: power (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.power)
    
    
    
    # Processing: stop (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.stop)
    
    
    
    # Processing: reset_angle (single)
    
    
    struct.pack_into('<I', base_buffer, 8, py_obj.reset_angle)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
