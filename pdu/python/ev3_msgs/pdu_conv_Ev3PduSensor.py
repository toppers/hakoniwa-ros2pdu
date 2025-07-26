
import struct
from .pdu_pytype_Ev3PduSensor import Ev3PduSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..ev3_msgs.pdu_conv_Ev3PduSensorHeader import *
from ..ev3_msgs.pdu_conv_Ev3PduColorSensor import *
from ..ev3_msgs.pdu_conv_Ev3PduTouchSensor import *



def pdu_to_py_Ev3PduSensor(binary_data: bytearray) -> Ev3PduSensor:
    py_obj = Ev3PduSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduSensor(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Ev3PduSensor, base_off: int):
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
    one_elm_size = int(40 / array_size)
    array_value = []
    while i < array_size:
        tmp_py_obj = Ev3PduColorSensor()
        binary_read_recursive_Ev3PduColorSensor(meta, binary_data, tmp_py_obj, base_off + 156 + (i * one_elm_size))
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
    one_elm_size = int(8 / array_size)
    array_value = []
    while i < array_size:
        tmp_py_obj = Ev3PduTouchSensor()
        binary_read_recursive_Ev3PduTouchSensor(meta, binary_data, tmp_py_obj, base_off + 196 + (i * one_elm_size))
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


def py_to_pdu_Ev3PduSensor(py_obj: Ev3PduSensor) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Ev3PduSensor(0, bw_container, base_allocator, py_obj)

    # メタデータの設定
    total_size = base_allocator.size() + bw_container.heap_allocator.size() + binary_io.PduMetaData.PDU_META_DATA_SIZE
    bw_container.meta.total_size = total_size
    bw_container.meta.heap_off = binary_io.PduMetaData.PDU_META_DATA_SIZE + base_allocator.size()

    # binary_data のサイズを total_size に調整
    if len(binary_data) < total_size:
        binary_data.extend(bytearray(total_size - len(binary_data)))
    elif len(binary_data) > total_size:
        del binary_data[total_size:]

    # メタデータをバッファにコピー
    binary_io.writeBinary(binary_data, 0, bw_container.meta.to_bytes())

    # 基本データをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.base_off, base_allocator.to_array())

    # ヒープデータをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.heap_off, bw_container.heap_allocator.to_array())

    return binary_data

def binary_write_recursive_Ev3PduSensor(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Ev3PduSensor):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: Ev3PduSensorHeader 
    # offset: 0 size: 152 
    # array_len: 1
    type = "Ev3PduSensorHeader"
    off = 0

    binary_write_recursive_Ev3PduSensorHeader(parent_off + off, bw_container, allocator, py_obj.head)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: buttons 
    # type_name: uint8 
    # offset: 152 size: 1 
    # array_len: 1
    type = "uint8"
    off = 152

    
    elm_size =  1 
    array_size = int(1.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.buttons, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    
    # array_type: array 
    # data_type: struct 
    # member_name: color_sensors 
    # type_name: Ev3PduColorSensor 
    # offset: 156 size: 40 
    # array_len: 2
    type = "Ev3PduColorSensor"
    off = 156

    for i, elm in enumerate(py_obj.color_sensors):
        elm_size = 40
        array_size = int(20.0)
        one_elm_size = int(elm_size / array_size)
        binary_write_recursive_Ev3PduColorSensor((parent_off + off + i * one_elm_size), bw_container, allocator, elm)
    
    # array_type: array 
    # data_type: struct 
    # member_name: touch_sensors 
    # type_name: Ev3PduTouchSensor 
    # offset: 196 size: 8 
    # array_len: 2
    type = "Ev3PduTouchSensor"
    off = 196

    for i, elm in enumerate(py_obj.touch_sensors):
        elm_size = 8
        array_size = int(4.0)
        one_elm_size = int(elm_size / array_size)
        binary_write_recursive_Ev3PduTouchSensor((parent_off + off + i * one_elm_size), bw_container, allocator, elm)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: motor_angle 
    # type_name: uint32 
    # offset: 204 size: 12 
    # array_len: 3
    type = "uint32"
    off = 204

    
    elm_size =  12 
    array_size = int(4.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.motor_angle, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gyro_degree 
    # type_name: int32 
    # offset: 216 size: 4 
    # array_len: 1
    type = "int32"
    off = 216

    
    bin = binary_io.typeTobin(type, py_obj.gyro_degree)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gyro_degree_rate 
    # type_name: int32 
    # offset: 220 size: 4 
    # array_len: 1
    type = "int32"
    off = 220

    
    bin = binary_io.typeTobin(type, py_obj.gyro_degree_rate)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: sensor_ultrasonic 
    # type_name: uint32 
    # offset: 224 size: 4 
    # array_len: 1
    type = "uint32"
    off = 224

    
    bin = binary_io.typeTobin(type, py_obj.sensor_ultrasonic)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gps_lat 
    # type_name: float64 
    # offset: 232 size: 8 
    # array_len: 1
    type = "float64"
    off = 232

    
    bin = binary_io.typeTobin(type, py_obj.gps_lat)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: gps_lon 
    # type_name: float64 
    # offset: 240 size: 8 
    # array_len: 1
    type = "float64"
    off = 240

    
    bin = binary_io.typeTobin(type, py_obj.gps_lon)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Ev3PduSensor <read|write> [args...]")
        print(f"  read <input_binary_file> <output_json_file>")
        print(f"  write <input_json_file> <output_binary_file>")

    if len(sys.argv) < 2:
        print_usage()
        sys.exit(1)

    command = sys.argv[1]

    if command == "read":
        if len(sys.argv) != 4:
            print_usage()
            sys.exit(1)
        
        binary_filepath = sys.argv[2]
        output_json_filepath = sys.argv[3]

        with open(binary_filepath, "rb") as f:
            binary_data = bytearray(f.read())
        
        py_obj = pdu_to_py_Ev3PduSensor(binary_data)
        
        with open(output_json_filepath, "w") as f:
            f.write(py_obj.to_json())

    elif command == "write":
        if len(sys.argv) != 4:
            print_usage()
            sys.exit(1)

        input_json_filepath = sys.argv[2]
        output_binary_filepath = sys.argv[3]

        with open(input_json_filepath, "r") as f:
            json_str = f.read()
        
        py_obj = Ev3PduSensor.from_json(json_str)
        
        binary_data = py_to_pdu_Ev3PduSensor(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
