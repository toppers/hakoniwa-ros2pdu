
import struct
from .pdu_pytype_Ev3PduActuator import Ev3PduActuator
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..ev3_msgs.pdu_conv_Ev3PduActuatorHeader import *
from ..ev3_msgs.pdu_conv_Ev3PduMotor import *



def pdu_to_py_Ev3PduActuator(binary_data: bytes) -> Ev3PduActuator:
    py_obj = Ev3PduActuator()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduActuator(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduActuator(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduActuator, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: Ev3PduActuatorHeader 
    # offset: 0 size: 152 
    # array_len: 1

    tmp_py_obj = Ev3PduActuatorHeader()
    binary_read_recursive_Ev3PduActuatorHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.head = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: leds 
    # type_name: uint8 
    # offset: 152 size: 1 
    # array_len: 1

    
    array_value = binary_io.readBinary(binary_data, base_off + 152, 1)
    py_obj.leds = binary_io.binToArrayValues(type, array_value)
    
    # array_type: array 
    # data_type: struct 
    # member_name: motors 
    # type_name: Ev3PduMotor 
    # offset: 156 size: 36 
    # array_len: 3

    i = 0
    array_size = 3
    one_elm_size = int(36) / array_size
    array_value = []
    while i < array_size:
        tmp_py_obj = Ev3PduMotor()
        binary_read_recursive_Ev3PduMotor(meta, binary_data, tmp_py_obj, 156 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.motors = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gyro_reset 
    # type_name: uint32 
    # offset: 192 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 192, 4)
    py_obj.gyro_reset = binary_io.binTovalue(type, bin)
    
    return py_obj
