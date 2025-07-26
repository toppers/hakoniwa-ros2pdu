
import struct
from .pdu_pytype_HakoGLOBAL_POSITION_INT import HakoGLOBAL_POSITION_INT
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoGLOBAL_POSITION_INT(binary_data: bytearray) -> HakoGLOBAL_POSITION_INT:
    py_obj = HakoGLOBAL_POSITION_INT()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoGLOBAL_POSITION_INT(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoGLOBAL_POSITION_INT(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoGLOBAL_POSITION_INT, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_boot_ms 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.time_boot_ms = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.lat = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.lon = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: relative_alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.relative_alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.vx = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 22 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 22, 2)
    py_obj.vy = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 24 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 2)
    py_obj.vz = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hdg 
    # type_name: uint16 
    # offset: 26 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 26, 2)
    py_obj.hdg = binary_io.binTovalue("uint16", bin)
    
    return py_obj


def py_to_pdu_HakoGLOBAL_POSITION_INT(py_obj: HakoGLOBAL_POSITION_INT) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoGLOBAL_POSITION_INT(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoGLOBAL_POSITION_INT(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoGLOBAL_POSITION_INT):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_boot_ms 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1
    type = "uint32"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.time_boot_ms)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 4 size: 4 
    # array_len: 1
    type = "int32"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.lat)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1
    type = "int32"
    off = 8

    
    bin = binary_io.typeTobin(type, py_obj.lon)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1
    type = "int32"
    off = 12

    
    bin = binary_io.typeTobin(type, py_obj.alt)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: relative_alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1
    type = "int32"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.relative_alt)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 20 size: 2 
    # array_len: 1
    type = "int16"
    off = 20

    
    bin = binary_io.typeTobin(type, py_obj.vx)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 22 size: 2 
    # array_len: 1
    type = "int16"
    off = 22

    
    bin = binary_io.typeTobin(type, py_obj.vy)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 24 size: 2 
    # array_len: 1
    type = "int16"
    off = 24

    
    bin = binary_io.typeTobin(type, py_obj.vz)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hdg 
    # type_name: uint16 
    # offset: 26 size: 2 
    # array_len: 1
    type = "uint16"
    off = 26

    
    bin = binary_io.typeTobin(type, py_obj.hdg)
    bin = get_binary(type, bin, 2)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoGLOBAL_POSITION_INT <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoGLOBAL_POSITION_INT(binary_data)
        
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
        
        py_obj = HakoGLOBAL_POSITION_INT.from_json(json_str)
        
        binary_data = py_to_pdu_HakoGLOBAL_POSITION_INT(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
