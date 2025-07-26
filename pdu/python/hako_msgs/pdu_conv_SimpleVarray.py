
import struct
from .pdu_pytype_SimpleVarray import SimpleVarray
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_SimpleVarray(binary_data: bytearray) -> SimpleVarray:
    py_obj = SimpleVarray()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_SimpleVarray(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_SimpleVarray(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: SimpleVarray, base_off: int):
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: int8 
    # offset: 0 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_array 
    # type_name: int8 
    # offset: 8 size: 10 
    # array_len: 10

    
    array_value = binary_io.readBinary(binary_data, base_off + 8, 10)
    py_obj.fixed_array = binary_io.binToArrayValues("int8", array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: p_mem1 
    # type_name: int32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.p_mem1 = binary_io.binTovalue("int32", bin)
    
    return py_obj


def py_to_pdu_SimpleVarray(py_obj: SimpleVarray) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_SimpleVarray(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_SimpleVarray(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: SimpleVarray):
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: int8 
    # offset: 0 size: 1 
    # array_len: 8
    type = "int8"
    off = 0

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.data)
    binary = binary_io.typeTobin_array(type, py_obj.data, 1)
    bw_container.heap_allocator.add(binary, expected_offset=0)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_array 
    # type_name: int8 
    # offset: 8 size: 10 
    # array_len: 10
    type = "int8"
    off = 8

    
    elm_size =  10 
    array_size = int(1.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.fixed_array, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    
    # array_type: single 
    # data_type: primitive 
    # member_name: p_mem1 
    # type_name: int32 
    # offset: 20 size: 4 
    # array_len: 1
    type = "int32"
    off = 20

    
    bin = binary_io.typeTobin(type, py_obj.p_mem1)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_SimpleVarray <read|write> [args...]")
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
        
        py_obj = pdu_to_py_SimpleVarray(binary_data)
        
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
        
        py_obj = SimpleVarray.from_json(json_str)
        
        binary_data = py_to_pdu_SimpleVarray(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
