
import struct
from .pdu_pytype_PointCloud2 import PointCloud2
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..sensor_msgs.pdu_conv_PointField import *



def pdu_to_py_PointCloud2(binary_data: bytearray) -> PointCloud2:
    py_obj = PointCloud2()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_PointCloud2(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_PointCloud2(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: PointCloud2, base_off: int):
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
    
    # array_type: varray 
    # data_type: struct 
    # member_name: fields 
    # type_name: PointField 
    # offset: 144 size: 140 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 144, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 144 + 4, 4))
    one_elm_size = 140
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = PointField()
        binary_read_recursive_PointField(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.fields = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: bool 
    # offset: 152 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 152, 4)
    py_obj.is_bigendian = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: point_step 
    # type_name: uint32 
    # offset: 156 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 156, 4)
    py_obj.point_step = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: row_step 
    # type_name: uint32 
    # offset: 160 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 160, 4)
    py_obj.row_step = binary_io.binTovalue("uint32", bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 164 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_dense 
    # type_name: bool 
    # offset: 172 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 172, 4)
    py_obj.is_dense = binary_io.binTovalue("bool", bin)
    
    return py_obj


def py_to_pdu_PointCloud2(py_obj: PointCloud2) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_PointCloud2(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_PointCloud2(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: PointCloud2):
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
    
    # array_type: varray 
    # data_type: struct 
    # member_name: fields 
    # type_name: PointField 
    # offset: 144 size: 140 
    # array_len: 8
    type = "PointField"
    off = 144

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.fields)
    for i, elm in enumerate(py_obj.fields):
        one_elm_size =  140
        binary_write_recursive_PointField((parent_off + i * one_elm_size), bw_container, bw_container.heap_allocator, elm)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: bool 
    # offset: 152 size: 4 
    # array_len: 1
    type = "bool"
    off = 152

    
    bin = binary_io.typeTobin(type, py_obj.is_bigendian)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: point_step 
    # type_name: uint32 
    # offset: 156 size: 4 
    # array_len: 1
    type = "uint32"
    off = 156

    
    bin = binary_io.typeTobin(type, py_obj.point_step)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: row_step 
    # type_name: uint32 
    # offset: 160 size: 4 
    # array_len: 1
    type = "uint32"
    off = 160

    
    bin = binary_io.typeTobin(type, py_obj.row_step)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 164 size: 1 
    # array_len: 8
    type = "uint8"
    off = 164

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.data)
    binary = binary_io.typeTobin_array(type, py_obj.data, 1)
    bw_container.heap_allocator.add(binary, expected_offset=0)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_dense 
    # type_name: bool 
    # offset: 172 size: 4 
    # array_len: 1
    type = "bool"
    off = 172

    
    bin = binary_io.typeTobin(type, py_obj.is_dense)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_PointCloud2 <read|write> [args...]")
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
        
        py_obj = pdu_to_py_PointCloud2(binary_data)
        
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
        
        py_obj = PointCloud2.from_json(json_str)
        
        binary_data = py_to_pdu_PointCloud2(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
