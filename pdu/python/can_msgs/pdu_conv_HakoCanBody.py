
import struct
from .pdu_pytype_HakoCanBody import HakoCanBody
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoCanBody(binary_data: bytearray) -> HakoCanBody:
    py_obj = HakoCanBody()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCanBody(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCanBody(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoCanBody, base_off: int):
    # array_type: array 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 0 size: 8 
    # array_len: 8

    
    array_value = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.data = binary_io.binToArrayValues("uint8", array_value)
    
    return py_obj


def py_to_pdu_HakoCanBody(py_obj: HakoCanBody) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoCanBody(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoCanBody(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoCanBody):
    # array_type: array 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 0 size: 8 
    # array_len: 8
    type = "uint8"
    off = 0

    
    elm_size =  8 
    array_size = int(1.0)
    one_elm_size = int(elm_size / array_size)
    binary = binary_io.typeTobin_array(type, py_obj.data, one_elm_size)
    allocator.add(binary, expected_offset=(parent_off + off))
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoCanBody <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoCanBody(binary_data)
        
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
        
        py_obj = HakoCanBody.from_json(json_str)
        
        binary_data = py_to_pdu_HakoCanBody(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
