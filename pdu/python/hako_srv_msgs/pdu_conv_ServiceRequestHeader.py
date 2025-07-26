
import struct
from .pdu_pytype_ServiceRequestHeader import ServiceRequestHeader
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_ServiceRequestHeader(binary_data: bytearray) -> ServiceRequestHeader:
    py_obj = ServiceRequestHeader()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ServiceRequestHeader(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ServiceRequestHeader(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: ServiceRequestHeader, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.request_id = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: service_name 
    # type_name: string 
    # offset: 4 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 128)
    py_obj.service_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: client_name 
    # type_name: string 
    # offset: 132 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 128)
    py_obj.client_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: opcode 
    # type_name: uint8 
    # offset: 260 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 260, 1)
    py_obj.opcode = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: status_poll_interval_msec 
    # type_name: int32 
    # offset: 264 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 264, 4)
    py_obj.status_poll_interval_msec = binary_io.binTovalue("int32", bin)
    
    return py_obj


def py_to_pdu_ServiceRequestHeader(py_obj: ServiceRequestHeader) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_ServiceRequestHeader(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_ServiceRequestHeader(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: ServiceRequestHeader):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1
    type = "uint32"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.request_id)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: service_name 
    # type_name: string 
    # offset: 4 size: 128 
    # array_len: 1
    type = "string"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.service_name)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: client_name 
    # type_name: string 
    # offset: 132 size: 128 
    # array_len: 1
    type = "string"
    off = 132

    
    bin = binary_io.typeTobin(type, py_obj.client_name)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: opcode 
    # type_name: uint8 
    # offset: 260 size: 1 
    # array_len: 1
    type = "uint8"
    off = 260

    
    bin = binary_io.typeTobin(type, py_obj.opcode)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: status_poll_interval_msec 
    # type_name: int32 
    # offset: 264 size: 4 
    # array_len: 1
    type = "int32"
    off = 264

    
    bin = binary_io.typeTobin(type, py_obj.status_poll_interval_msec)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_ServiceRequestHeader <read|write> [args...]")
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
        
        py_obj = pdu_to_py_ServiceRequestHeader(binary_data)
        
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
        
        py_obj = ServiceRequestHeader.from_json(json_str)
        
        binary_data = py_to_pdu_ServiceRequestHeader(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
