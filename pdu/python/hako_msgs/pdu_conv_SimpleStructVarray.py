
import struct
from .pdu_pytype_SimpleStructVarray import SimpleStructVarray
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_SimpleVarray import *
from ..hako_msgs.pdu_conv_SimpleVarray import *



def pdu_to_py_SimpleStructVarray(binary_data: bytearray) -> SimpleStructVarray:
    py_obj = SimpleStructVarray()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_SimpleStructVarray(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_SimpleStructVarray(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: SimpleStructVarray, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: aaa 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.aaa = binary_io.binTovalue("int32", bin)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_str 
    # type_name: string 
    # offset: 4 size: 256 
    # array_len: 2

    
    array_value = binary_io.readBinary(binary_data, base_off + 4, 256)
    py_obj.fixed_str = binary_io.binToArrayValues("string", array_value)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: varray_str 
    # type_name: string 
    # offset: 260 size: 128 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 260, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 260 + 4, 4))
    one_elm_size = 128 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.varray_str = array_value
    
    # array_type: array 
    # data_type: struct 
    # member_name: fixed_array 
    # type_name: SimpleVarray 
    # offset: 268 size: 120 
    # array_len: 5

    i = 0
    array_size = 5
    one_elm_size = int(120 / array_size)
    array_value = []
    while i < array_size:
        tmp_py_obj = SimpleVarray()
        binary_read_recursive_SimpleVarray(meta, binary_data, tmp_py_obj, base_off + 268 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.fixed_array = array_value    
    
    # array_type: varray 
    # data_type: struct 
    # member_name: data 
    # type_name: SimpleVarray 
    # offset: 388 size: 24 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 388, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 388 + 4, 4))
    one_elm_size = 24
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = SimpleVarray()
        binary_read_recursive_SimpleVarray(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.data = array_value    
    
    return py_obj


def py_to_pdu_SimpleStructVarray(py_obj: SimpleStructVarray) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_SimpleStructVarray(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_SimpleStructVarray(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: SimpleStructVarray):
    # array_type: single 
    # data_type: primitive 
    # member_name: aaa 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1
    type = "int32"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.aaa)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_str 
    # type_name: string 
    # offset: 4 size: 256 
    # array_len: 2
    type = "string"
    off = 4

    
    elm_size =  256 
    array_size = int(128.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.fixed_str, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: varray_str 
    # type_name: string 
    # offset: 260 size: 128 
    # array_len: 8
    type = "string"
    off = 260

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.varray_str)
    binary = binary_io.typeTobin_array(type, py_obj.varray_str, 128)
    bw_container.heap_allocator.add(binary, expected_offset=0)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    
    # array_type: array 
    # data_type: struct 
    # member_name: fixed_array 
    # type_name: SimpleVarray 
    # offset: 268 size: 120 
    # array_len: 5
    type = "SimpleVarray"
    off = 268

    for i, elm in enumerate(py_obj.fixed_array):
        elm_size = 120
        array_size = int(24.0)
        one_elm_size = int(elm_size / array_size)
        binary_write_recursive_SimpleVarray((parent_off + off + i * one_elm_size), bw_container, allocator, elm)
    
    # array_type: varray 
    # data_type: struct 
    # member_name: data 
    # type_name: SimpleVarray 
    # offset: 388 size: 24 
    # array_len: 8
    type = "SimpleVarray"
    off = 388

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.data)
    for i, elm in enumerate(py_obj.data):
        one_elm_size =  24
        binary_write_recursive_SimpleVarray((parent_off + i * one_elm_size), bw_container, bw_container.heap_allocator, elm)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)    
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_SimpleStructVarray <read|write> [args...]")
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
        
        py_obj = pdu_to_py_SimpleStructVarray(binary_data)
        
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
        
        py_obj = SimpleStructVarray.from_json(json_str)
        
        binary_data = py_to_pdu_SimpleStructVarray(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
