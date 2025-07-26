
import struct
from .pdu_pytype_HakoDroneCmdMove import HakoDroneCmdMove
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_HakoDroneCmdHeader import *



def pdu_to_py_HakoDroneCmdMove(binary_data: bytearray) -> HakoDroneCmdMove:
    py_obj = HakoDroneCmdMove()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoDroneCmdMove(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoDroneCmdMove(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoDroneCmdMove, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: HakoDroneCmdHeader 
    # offset: 0 size: 12 
    # array_len: 1

    tmp_py_obj = HakoDroneCmdHeader()
    binary_read_recursive_HakoDroneCmdHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: x 
    # type_name: float64 
    # offset: 16 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 8)
    py_obj.x = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: y 
    # type_name: float64 
    # offset: 24 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 8)
    py_obj.y = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: z 
    # type_name: float64 
    # offset: 32 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 8)
    py_obj.z = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: speed 
    # type_name: float64 
    # offset: 40 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 40, 8)
    py_obj.speed = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_deg 
    # type_name: float64 
    # offset: 48 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 48, 8)
    py_obj.yaw_deg = binary_io.binTovalue("float64", bin)
    
    return py_obj


def py_to_pdu_HakoDroneCmdMove(py_obj: HakoDroneCmdMove) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoDroneCmdMove(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoDroneCmdMove(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoDroneCmdMove):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: HakoDroneCmdHeader 
    # offset: 0 size: 12 
    # array_len: 1
    type = "HakoDroneCmdHeader"
    off = 0

    binary_write_recursive_HakoDroneCmdHeader(parent_off + off, bw_container, allocator, py_obj.header)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: x 
    # type_name: float64 
    # offset: 16 size: 8 
    # array_len: 1
    type = "float64"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.x)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: y 
    # type_name: float64 
    # offset: 24 size: 8 
    # array_len: 1
    type = "float64"
    off = 24

    
    bin = binary_io.typeTobin(type, py_obj.y)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: z 
    # type_name: float64 
    # offset: 32 size: 8 
    # array_len: 1
    type = "float64"
    off = 32

    
    bin = binary_io.typeTobin(type, py_obj.z)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: speed 
    # type_name: float64 
    # offset: 40 size: 8 
    # array_len: 1
    type = "float64"
    off = 40

    
    bin = binary_io.typeTobin(type, py_obj.speed)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_deg 
    # type_name: float64 
    # offset: 48 size: 8 
    # array_len: 1
    type = "float64"
    off = 48

    
    bin = binary_io.typeTobin(type, py_obj.yaw_deg)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_HakoDroneCmdMove <read|write> [args...]")
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
        
        py_obj = pdu_to_py_HakoDroneCmdMove(binary_data)
        
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
        
        py_obj = HakoDroneCmdMove.from_json(json_str)
        
        binary_data = py_to_pdu_HakoDroneCmdMove(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
