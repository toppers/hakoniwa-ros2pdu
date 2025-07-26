
import struct
from .pdu_pytype_HakoHilGps import HakoHilGps
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilGps(binary_data: bytearray) -> HakoHilGps:
    py_obj = HakoHilGps()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilGps(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilGps(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoHilGps, base_off: int):
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
    # member_name: lat 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.lat = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.lon = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: eph 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.eph = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: epv 
    # type_name: uint16 
    # offset: 22 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 22, 2)
    py_obj.epv = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vel 
    # type_name: uint16 
    # offset: 24 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 2)
    py_obj.vel = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vn 
    # type_name: int16 
    # offset: 26 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 26, 2)
    py_obj.vn = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ve 
    # type_name: int16 
    # offset: 28 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 2)
    py_obj.ve = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vd 
    # type_name: int16 
    # offset: 30 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 30, 2)
    py_obj.vd = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: cog 
    # type_name: uint16 
    # offset: 32 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 2)
    py_obj.cog = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: satellites_visible 
    # type_name: uint8 
    # offset: 34 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 34, 1)
    py_obj.satellites_visible = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 35 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 35, 1)
    py_obj.id = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw 
    # type_name: uint8 
    # offset: 36 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 1)
    py_obj.yaw = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fix_type 
    # type_name: uint8 
    # offset: 37 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 37, 1)
    py_obj.fix_type = binary_io.binTovalue("uint8", bin)
    
    return py_obj


def py_to_pdu_HakoHilGps(py_obj: HakoHilGps) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoHilGps(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoHilGps(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoHilGps):
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
    # member_name: lat 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1
    type = "int32"
    off = 8

    
    bin = binary_io.typeTobin(type, py_obj.lat)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1
    type = "int32"
    off = 12

    
    bin = binary_io.typeTobin(type, py_obj.lon)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1
    type = "int32"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.alt)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: eph 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1
    type = "uint16"
    off = 20

    
    bin = binary_io.typeTobin(type, py_obj.eph)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: epv 
    # type_name: uint16 
    # offset: 22 size: 2 
    # array_len: 1
    type = "uint16"
    off = 22

    
    bin = binary_io.typeTobin(type, py_obj.epv)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vel 
    # type_name: uint16 
    # offset: 24 size: 2 
    # array_len: 1
    type = "uint16"
    off = 24

    
    bin = binary_io.typeTobin(type, py_obj.vel)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vn 
    # type_name: int16 
    # offset: 26 size: 2 
    # array_len: 1
    type = "int16"
    off = 26

    
    bin = binary_io.typeTobin(type, py_obj.vn)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ve 
    # type_name: int16 
    # offset: 28 size: 2 
    # array_len: 1
    type = "int16"
    off = 28

    
    bin = binary_io.typeTobin(type, py_obj.ve)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vd 
    # type_name: int16 
    # offset: 30 size: 2 
    # array_len: 1
    type = "int16"
    off = 30

    
    bin = binary_io.typeTobin(type, py_obj.vd)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: cog 
    # type_name: uint16 
    # offset: 32 size: 2 
    # array_len: 1
    type = "uint16"
    off = 32

    
    bin = binary_io.typeTobin(type, py_obj.cog)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: satellites_visible 
    # type_name: uint8 
    # offset: 34 size: 1 
    # array_len: 1
    type = "uint8"
    off = 34

    
    bin = binary_io.typeTobin(type, py_obj.satellites_visible)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 35 size: 1 
    # array_len: 1
    type = "uint8"
    off = 35

    
    bin = binary_io.typeTobin(type, py_obj.id)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw 
    # type_name: uint8 
    # offset: 36 size: 1 
    # array_len: 1
    type = "uint8"
    off = 36

    
    bin = binary_io.typeTobin(type, py_obj.yaw)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fix_type 
    # type_name: uint8 
    # offset: 37 size: 1 
    # array_len: 1
    type = "uint8"
    off = 37

    
    bin = binary_io.typeTobin(type, py_obj.fix_type)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoHilGps <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoHilGps(binary_data)
        
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
        
        py_obj = HakoHilGps.from_json(json_str)
        
        binary_data = py_to_pdu_HakoHilGps(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
