
import struct
from .pdu_pytype_HakoHilSensor import HakoHilSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilSensor(binary_data: bytearray) -> HakoHilSensor:
    py_obj = HakoHilSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilSensor(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoHilSensor, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue("uint64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: float32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.xacc = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: float32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.yacc = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: float32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.zacc = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xgyro 
    # type_name: float32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.xgyro = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ygyro 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.ygyro = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zgyro 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 4)
    py_obj.zgyro = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xmag 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 4)
    py_obj.xmag = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ymag 
    # type_name: float32 
    # offset: 36 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 4)
    py_obj.ymag = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zmag 
    # type_name: float32 
    # offset: 40 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 40, 4)
    py_obj.zmag = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: abs_pressure 
    # type_name: float32 
    # offset: 44 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 44, 4)
    py_obj.abs_pressure = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: diff_pressure 
    # type_name: float32 
    # offset: 48 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 48, 4)
    py_obj.diff_pressure = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pressure_alt 
    # type_name: float32 
    # offset: 52 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 52, 4)
    py_obj.pressure_alt = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: temperature 
    # type_name: float32 
    # offset: 56 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 56, 4)
    py_obj.temperature = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fields_updated 
    # type_name: uint32 
    # offset: 60 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 60, 4)
    py_obj.fields_updated = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 64 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 64, 1)
    py_obj.id = binary_io.binTovalue("uint8", bin)
    
    return py_obj


def py_to_pdu_HakoHilSensor(py_obj: HakoHilSensor) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoHilSensor(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoHilSensor(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoHilSensor):
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
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: float32 
    # offset: 8 size: 4 
    # array_len: 1
    type = "float32"
    off = 8

    
    bin = binary_io.typeTobin(type, py_obj.xacc)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: float32 
    # offset: 12 size: 4 
    # array_len: 1
    type = "float32"
    off = 12

    
    bin = binary_io.typeTobin(type, py_obj.yacc)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: float32 
    # offset: 16 size: 4 
    # array_len: 1
    type = "float32"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.zacc)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xgyro 
    # type_name: float32 
    # offset: 20 size: 4 
    # array_len: 1
    type = "float32"
    off = 20

    
    bin = binary_io.typeTobin(type, py_obj.xgyro)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ygyro 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1
    type = "float32"
    off = 24

    
    bin = binary_io.typeTobin(type, py_obj.ygyro)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zgyro 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1
    type = "float32"
    off = 28

    
    bin = binary_io.typeTobin(type, py_obj.zgyro)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xmag 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1
    type = "float32"
    off = 32

    
    bin = binary_io.typeTobin(type, py_obj.xmag)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ymag 
    # type_name: float32 
    # offset: 36 size: 4 
    # array_len: 1
    type = "float32"
    off = 36

    
    bin = binary_io.typeTobin(type, py_obj.ymag)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zmag 
    # type_name: float32 
    # offset: 40 size: 4 
    # array_len: 1
    type = "float32"
    off = 40

    
    bin = binary_io.typeTobin(type, py_obj.zmag)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: abs_pressure 
    # type_name: float32 
    # offset: 44 size: 4 
    # array_len: 1
    type = "float32"
    off = 44

    
    bin = binary_io.typeTobin(type, py_obj.abs_pressure)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: diff_pressure 
    # type_name: float32 
    # offset: 48 size: 4 
    # array_len: 1
    type = "float32"
    off = 48

    
    bin = binary_io.typeTobin(type, py_obj.diff_pressure)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pressure_alt 
    # type_name: float32 
    # offset: 52 size: 4 
    # array_len: 1
    type = "float32"
    off = 52

    
    bin = binary_io.typeTobin(type, py_obj.pressure_alt)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: temperature 
    # type_name: float32 
    # offset: 56 size: 4 
    # array_len: 1
    type = "float32"
    off = 56

    
    bin = binary_io.typeTobin(type, py_obj.temperature)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fields_updated 
    # type_name: uint32 
    # offset: 60 size: 4 
    # array_len: 1
    type = "uint32"
    off = 60

    
    bin = binary_io.typeTobin(type, py_obj.fields_updated)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 64 size: 1 
    # array_len: 1
    type = "uint8"
    off = 64

    
    bin = binary_io.typeTobin(type, py_obj.id)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoHilSensor <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoHilSensor(binary_data)
        
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
        
        py_obj = HakoHilSensor.from_json(json_str)
        
        binary_data = py_to_pdu_HakoHilSensor(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
