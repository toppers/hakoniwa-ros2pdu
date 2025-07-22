
import struct
from .pdu_pytype_Ev3PduSensor import Ev3PduSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..ev3_msgs.pdu_conv_Ev3PduSensorHeader import *
from ..ev3_msgs.pdu_conv_Ev3PduColorSensor import *
from ..ev3_msgs.pdu_conv_Ev3PduTouchSensor import *



def pdu_to_py_Ev3PduSensor(binary_data: bytes) -> Ev3PduSensor:
    py_obj = Ev3PduSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduSensor(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduSensor, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: Ev3PduSensorHeader 
    # offset: 0 size: 152 
    # array_len: 1

    tmp_py_obj = Ev3PduSensorHeader()
    binary_read_recursive_Ev3PduSensorHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.head = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: buttons 
    # type_name: uint8 
    # offset: 152 size: 1 
    # array_len: 1

    
    array_value = binary_io.readBinary(binary_data, base_off + 152, 1)
    py_obj.buttons = binary_io.binToArrayValues("uint8", array_value)
    
    # array_type: array 
    # data_type: struct 
    # member_name: color_sensors 
    # type_name: Ev3PduColorSensor 
    # offset: 156 size: 40 
    # array_len: 2

    i = 0
    array_size = 2
    one_elm_size = int(40) / array_size
    array_value = []
    while i < array_size:
        tmp_py_obj = Ev3PduColorSensor()
        binary_read_recursive_Ev3PduColorSensor(meta, binary_data, tmp_py_obj, 156 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.color_sensors = array_value    
    
    # array_type: array 
    # data_type: struct 
    # member_name: touch_sensors 
    # type_name: Ev3PduTouchSensor 
    # offset: 196 size: 8 
    # array_len: 2

    i = 0
    array_size = 2
    one_elm_size = int(8) / array_size
    array_value = []
    while i < array_size:
        tmp_py_obj = Ev3PduTouchSensor()
        binary_read_recursive_Ev3PduTouchSensor(meta, binary_data, tmp_py_obj, 196 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.touch_sensors = array_value    
    
    # array_type: array 
    # data_type: primitive 
    # member_name: motor_angle 
    # type_name: uint32 
    # offset: 204 size: 12 
    # array_len: 3

    
    array_value = binary_io.readBinary(binary_data, base_off + 204, 12)
    py_obj.motor_angle = binary_io.binToArrayValues("uint32", array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gyro_degree 
    # type_name: int32 
    # offset: 216 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 216, 4)
    py_obj.gyro_degree = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gyro_degree_rate 
    # type_name: int32 
    # offset: 220 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 220, 4)
    py_obj.gyro_degree_rate = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: sensor_ultrasonic 
    # type_name: uint32 
    # offset: 224 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 224, 4)
    py_obj.sensor_ultrasonic = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gps_lat 
    # type_name: float64 
    # offset: 232 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 232, 8)
    py_obj.gps_lat = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gps_lon 
    # type_name: float64 
    # offset: 240 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 240, 8)
    py_obj.gps_lon = binary_io.binTovalue("float64", bin)
    
    return py_obj
