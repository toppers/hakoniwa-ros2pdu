
import struct
from .pdu_pytype_HakoStatusMagnetHolder import HakoStatusMagnetHolder
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoStatusMagnetHolder(binary_data: bytearray) -> HakoStatusMagnetHolder:
    py_obj = HakoStatusMagnetHolder()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoStatusMagnetHolder(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoStatusMagnetHolder(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoStatusMagnetHolder, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: magnet_on 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.magnet_on = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: contact_on 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.contact_on = binary_io.binTovalue("bool", bin)
    
    return py_obj


def py_to_pdu_HakoStatusMagnetHolder(py_obj: HakoStatusMagnetHolder) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoStatusMagnetHolder(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoStatusMagnetHolder(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoStatusMagnetHolder):
    # array_type: single 
    # data_type: primitive 
    # member_name: magnet_on 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1
    type = "bool"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.magnet_on)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: contact_on 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1
    type = "bool"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.contact_on)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoStatusMagnetHolder <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoStatusMagnetHolder(binary_data)
        
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
        
        py_obj = HakoStatusMagnetHolder.from_json(json_str)
        
        binary_data = py_to_pdu_HakoStatusMagnetHolder(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
