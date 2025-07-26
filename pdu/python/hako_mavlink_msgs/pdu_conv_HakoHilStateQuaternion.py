
import struct
from .pdu_pytype_HakoHilStateQuaternion import HakoHilStateQuaternion
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilStateQuaternion(binary_data: bytearray) -> HakoHilStateQuaternion:
    py_obj = HakoHilStateQuaternion()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilStateQuaternion(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilStateQuaternion(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoHilStateQuaternion, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue("uint64", bin)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: attitude_quaternion 
    # type_name: float32 
    # offset: 8 size: 16 
    # array_len: 4

    
    array_value = binary_io.readBinary(binary_data, base_off + 8, 16)
    py_obj.attitude_quaternion = binary_io.binToArrayValues("float32", array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rollspeed 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.rollspeed = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pitchspeed 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 4)
    py_obj.pitchspeed = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yawspeed 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 4)
    py_obj.yawspeed = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 36 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 4)
    py_obj.lat = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 40 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 40, 4)
    py_obj.lon = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 44 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 44, 4)
    py_obj.alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 48 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 48, 2)
    py_obj.vx = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 50 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 50, 2)
    py_obj.vy = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 52 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 52, 2)
    py_obj.vz = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ind_airspeed 
    # type_name: uint16 
    # offset: 54 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 54, 2)
    py_obj.ind_airspeed = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: true_airspeed 
    # type_name: uint16 
    # offset: 56 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 56, 2)
    py_obj.true_airspeed = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: int16 
    # offset: 58 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 58, 2)
    py_obj.xacc = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: int16 
    # offset: 60 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 60, 2)
    py_obj.yacc = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: int16 
    # offset: 62 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 62, 2)
    py_obj.zacc = binary_io.binTovalue("int16", bin)
    
    return py_obj


def py_to_pdu_HakoHilStateQuaternion(py_obj: HakoHilStateQuaternion) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoHilStateQuaternion(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoHilStateQuaternion(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoHilStateQuaternion):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1
    type = "uint64"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.time_usec)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: attitude_quaternion 
    # type_name: float32 
    # offset: 8 size: 16 
    # array_len: 4
    type = "float32"
    off = 8

    
    elm_size =  16 
    array_size = int(4.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.attitude_quaternion, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rollspeed 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1
    type = "float32"
    off = 24

    
    bin = binary_io.typeTobin(type, py_obj.rollspeed)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pitchspeed 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1
    type = "float32"
    off = 28

    
    bin = binary_io.typeTobin(type, py_obj.pitchspeed)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yawspeed 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1
    type = "float32"
    off = 32

    
    bin = binary_io.typeTobin(type, py_obj.yawspeed)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 36 size: 4 
    # array_len: 1
    type = "int32"
    off = 36

    
    bin = binary_io.typeTobin(type, py_obj.lat)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 40 size: 4 
    # array_len: 1
    type = "int32"
    off = 40

    
    bin = binary_io.typeTobin(type, py_obj.lon)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 44 size: 4 
    # array_len: 1
    type = "int32"
    off = 44

    
    bin = binary_io.typeTobin(type, py_obj.alt)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 48 size: 2 
    # array_len: 1
    type = "int16"
    off = 48

    
    bin = binary_io.typeTobin(type, py_obj.vx)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 50 size: 2 
    # array_len: 1
    type = "int16"
    off = 50

    
    bin = binary_io.typeTobin(type, py_obj.vy)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 52 size: 2 
    # array_len: 1
    type = "int16"
    off = 52

    
    bin = binary_io.typeTobin(type, py_obj.vz)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ind_airspeed 
    # type_name: uint16 
    # offset: 54 size: 2 
    # array_len: 1
    type = "uint16"
    off = 54

    
    bin = binary_io.typeTobin(type, py_obj.ind_airspeed)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: true_airspeed 
    # type_name: uint16 
    # offset: 56 size: 2 
    # array_len: 1
    type = "uint16"
    off = 56

    
    bin = binary_io.typeTobin(type, py_obj.true_airspeed)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: int16 
    # offset: 58 size: 2 
    # array_len: 1
    type = "int16"
    off = 58

    
    bin = binary_io.typeTobin(type, py_obj.xacc)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: int16 
    # offset: 60 size: 2 
    # array_len: 1
    type = "int16"
    off = 60

    
    bin = binary_io.typeTobin(type, py_obj.yacc)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: int16 
    # offset: 62 size: 2 
    # array_len: 1
    type = "int16"
    off = 62

    
    bin = binary_io.typeTobin(type, py_obj.zacc)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoHilStateQuaternion <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoHilStateQuaternion(binary_data)
        
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
        
        py_obj = HakoHilStateQuaternion.from_json(json_str)
        
        binary_data = py_to_pdu_HakoHilStateQuaternion(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
