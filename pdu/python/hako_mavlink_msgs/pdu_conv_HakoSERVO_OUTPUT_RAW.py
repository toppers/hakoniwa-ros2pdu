
import struct
from .pdu_pytype_HakoSERVO_OUTPUT_RAW import HakoSERVO_OUTPUT_RAW
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoSERVO_OUTPUT_RAW(binary_data: bytearray) -> HakoSERVO_OUTPUT_RAW:
    py_obj = HakoSERVO_OUTPUT_RAW()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoSERVO_OUTPUT_RAW, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.time_usec = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: port 
    # type_name: uint8 
    # offset: 4 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 1)
    py_obj.port = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo1_raw 
    # type_name: uint16 
    # offset: 6 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 6, 2)
    py_obj.servo1_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo2_raw 
    # type_name: uint16 
    # offset: 8 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 2)
    py_obj.servo2_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo3_raw 
    # type_name: uint16 
    # offset: 10 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 10, 2)
    py_obj.servo3_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo4_raw 
    # type_name: uint16 
    # offset: 12 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 2)
    py_obj.servo4_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo5_raw 
    # type_name: uint16 
    # offset: 14 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 14, 2)
    py_obj.servo5_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo6_raw 
    # type_name: uint16 
    # offset: 16 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 2)
    py_obj.servo6_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo7_raw 
    # type_name: uint16 
    # offset: 18 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 18, 2)
    py_obj.servo7_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo8_raw 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.servo8_raw = binary_io.binTovalue("uint16", bin)
    
    return py_obj


def py_to_pdu_HakoSERVO_OUTPUT_RAW(py_obj: HakoSERVO_OUTPUT_RAW) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoSERVO_OUTPUT_RAW(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoSERVO_OUTPUT_RAW(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoSERVO_OUTPUT_RAW):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1
    type = "uint32"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.time_usec)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: port 
    # type_name: uint8 
    # offset: 4 size: 1 
    # array_len: 1
    type = "uint8"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.port)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo1_raw 
    # type_name: uint16 
    # offset: 6 size: 2 
    # array_len: 1
    type = "uint16"
    off = 6

    
    bin = binary_io.typeTobin(type, py_obj.servo1_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo2_raw 
    # type_name: uint16 
    # offset: 8 size: 2 
    # array_len: 1
    type = "uint16"
    off = 8

    
    bin = binary_io.typeTobin(type, py_obj.servo2_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo3_raw 
    # type_name: uint16 
    # offset: 10 size: 2 
    # array_len: 1
    type = "uint16"
    off = 10

    
    bin = binary_io.typeTobin(type, py_obj.servo3_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo4_raw 
    # type_name: uint16 
    # offset: 12 size: 2 
    # array_len: 1
    type = "uint16"
    off = 12

    
    bin = binary_io.typeTobin(type, py_obj.servo4_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo5_raw 
    # type_name: uint16 
    # offset: 14 size: 2 
    # array_len: 1
    type = "uint16"
    off = 14

    
    bin = binary_io.typeTobin(type, py_obj.servo5_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo6_raw 
    # type_name: uint16 
    # offset: 16 size: 2 
    # array_len: 1
    type = "uint16"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.servo6_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo7_raw 
    # type_name: uint16 
    # offset: 18 size: 2 
    # array_len: 1
    type = "uint16"
    off = 18

    
    bin = binary_io.typeTobin(type, py_obj.servo7_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo8_raw 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1
    type = "uint16"
    off = 20

    
    bin = binary_io.typeTobin(type, py_obj.servo8_raw)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoSERVO_OUTPUT_RAW <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoSERVO_OUTPUT_RAW(binary_data)
        
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
        
        py_obj = HakoSERVO_OUTPUT_RAW.from_json(json_str)
        
        binary_data = py_to_pdu_HakoSERVO_OUTPUT_RAW(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
