
import struct
from .pdu_pytype_Image import Image
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *



def pdu_to_py_Image(binary_data: bytearray) -> Image:
    py_obj = Image()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Image(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Image(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Image, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: std_msgs/Header 
    # offset: 0 size: 136 
    # array_len: 1

    tmp_py_obj = Header()
    binary_read_recursive_Header(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: height 
    # type_name: uint32 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.height = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 140 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 140, 4)
    py_obj.width = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encoding 
    # type_name: string 
    # offset: 144 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 128)
    py_obj.encoding = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: uint8 
    # offset: 272 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 272, 1)
    py_obj.is_bigendian = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: step 
    # type_name: uint32 
    # offset: 276 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 276, 4)
    py_obj.step = binary_io.binTovalue("uint32", bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 280 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 280, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 280 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    return py_obj


def py_to_pdu_Image(py_obj: Image) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Image(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_Image(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Image):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: std_msgs/Header 
    # offset: 0 size: 136 
    # array_len: 1
    type = "Header"
    off = 0

    binary_write_recursive_Header(parent_off + off, bw_container, allocator, py_obj.header)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: height 
    # type_name: uint32 
    # offset: 136 size: 4 
    # array_len: 1
    type = "uint32"
    off = 136

    
    bin = binary_io.typeTobin(type, py_obj.height)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 140 size: 4 
    # array_len: 1
    type = "uint32"
    off = 140

    
    bin = binary_io.typeTobin(type, py_obj.width)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encoding 
    # type_name: string 
    # offset: 144 size: 128 
    # array_len: 1
    type = "string"
    off = 144

    
    bin = binary_io.typeTobin(type, py_obj.encoding)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: uint8 
    # offset: 272 size: 1 
    # array_len: 1
    type = "uint8"
    off = 272

    
    bin = binary_io.typeTobin(type, py_obj.is_bigendian)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: step 
    # type_name: uint32 
    # offset: 276 size: 4 
    # array_len: 1
    type = "uint32"
    off = 276

    
    bin = binary_io.typeTobin(type, py_obj.step)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 280 size: 1 
    # array_len: 8
    type = "uint8"
    off = 280

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.data)
    binary = binary_io.typeTobin_array(type, py_obj.data, 1)
    bw_container.heap_allocator.add(binary, expected_offset=0)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Image <read|write> [args...]")
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
        
        py_obj = pdu_to_py_Image(binary_data)
        
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
        
        py_obj = Image.from_json(json_str)
        
        binary_data = py_to_pdu_Image(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
