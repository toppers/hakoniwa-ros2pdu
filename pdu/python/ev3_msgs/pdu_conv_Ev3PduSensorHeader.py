
import struct
from .pdu_pytype_Ev3PduSensorHeader import Ev3PduSensorHeader
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Ev3PduSensorHeader(binary_data: bytearray) -> Ev3PduSensorHeader:
    py_obj = Ev3PduSensorHeader()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduSensorHeader(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduSensorHeader(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Ev3PduSensorHeader, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: version 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.version = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hakoniwa_time 
    # type_name: int64 
    # offset: 136 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 8)
    py_obj.hakoniwa_time = binary_io.binTovalue("int64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_off 
    # type_name: uint32 
    # offset: 144 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 4)
    py_obj.ext_off = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_size 
    # type_name: uint32 
    # offset: 148 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 148, 4)
    py_obj.ext_size = binary_io.binTovalue("uint32", bin)
    
    return py_obj


def py_to_pdu_Ev3PduSensorHeader(py_obj: Ev3PduSensorHeader) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Ev3PduSensorHeader(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_Ev3PduSensorHeader(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Ev3PduSensorHeader):
    # array_type: single 
    # data_type: primitive 
    # member_name: name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1
    type = "string"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.name)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: version 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1
    type = "uint32"
    off = 128

    
    bin = binary_io.typeTobin(type, py_obj.version)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hakoniwa_time 
    # type_name: int64 
    # offset: 136 size: 8 
    # array_len: 1
    type = "int64"
    off = 136

    
    bin = binary_io.typeTobin(type, py_obj.hakoniwa_time)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_off 
    # type_name: uint32 
    # offset: 144 size: 4 
    # array_len: 1
    type = "uint32"
    off = 144

    
    bin = binary_io.typeTobin(type, py_obj.ext_off)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_size 
    # type_name: uint32 
    # offset: 148 size: 4 
    # array_len: 1
    type = "uint32"
    off = 148

    
    bin = binary_io.typeTobin(type, py_obj.ext_size)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Ev3PduSensorHeader <read|write> [args...]")
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
        
        py_obj = pdu_to_py_Ev3PduSensorHeader(binary_data)
        
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
        
        py_obj = Ev3PduSensorHeader.from_json(json_str)
        
        binary_data = py_to_pdu_Ev3PduSensorHeader(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
