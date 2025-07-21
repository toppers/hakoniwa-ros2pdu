
import struct
from .pdu_pytype_Ev3PduActuator import Ev3PduActuator
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..ev3_msgs.pdu_conv_Ev3PduActuatorHeader import pdu_to_py_, py_to_pdu_

from ..ev3_msgs.pdu_conv_Ev3PduMotor import pdu_to_py_, py_to_pdu_


def pdu_to_py_Ev3PduActuator(pdu_bytes: bytes) -> Ev3PduActuator:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Ev3PduActuator()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: head (single)
    
    
    nested_base_data = base_data[0:152]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.head = pdu_to_py_Ev3PduActuatorHeader(nested_pdu_bytes)
    
    
    
    # Processing: leds (array)
    
    py_obj.leds = []
    element_size = 1
    for i in range(1):
        element_offset = 152 + i * element_size
    
        val = struct.unpack_from('<B', base_data, element_offset)[0]
        py_obj.leds.append(val)
    
    
    
    # Processing: motors (array)
    
    py_obj.motors = []
    element_size = 12
    for i in range(3):
        element_offset = 156 + i * element_size
    
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_Ev3PduMotor(nested_pdu_bytes)
        py_obj.motors.append(val)
    
    
    
    # Processing: gyro_reset (single)
    
    
    py_obj.gyro_reset = struct.unpack_from('<I', base_data, 192)[0]
    
    
    
    return py_obj

def py_to_pdu_Ev3PduActuator(py_obj: Ev3PduActuator) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 196
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: head (single)
    
    
    nested_pdu_bytes = py_to_pdu_Ev3PduActuatorHeader(py_obj.head)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:152] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: leds (array)
    
    element_size = 1
    for i, element in enumerate(py_obj.leds):
        if i >= 1: break
        element_offset = 152 + i * element_size
    
        struct.pack_into('<B', base_buffer, element_offset, element)
    
    
    
    # Processing: motors (array)
    
    element_size = 12
    for i, element in enumerate(py_obj.motors):
        if i >= 3: break
        element_offset = 156 + i * element_size
    
        nested_pdu_bytes = py_to_pdu_Ev3PduMotor(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    
    
    
    # Processing: gyro_reset (single)
    
    
    struct.pack_into('<I', base_buffer, 192, py_obj.gyro_reset)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
