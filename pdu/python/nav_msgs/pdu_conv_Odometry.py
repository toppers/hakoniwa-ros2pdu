
import struct
from .pdu_pytype_Odometry import Odometry
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_PoseWithCovariance import *
from ..geometry_msgs.pdu_conv_TwistWithCovariance import *



def pdu_to_py_Odometry(binary_data: bytearray) -> Odometry:
    py_obj = Odometry()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Odometry(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Odometry(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Odometry, base_off: int):
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
    # member_name: child_frame_id 
    # type_name: string 
    # offset: 136 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 128)
    py_obj.child_frame_id = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: pose 
    # type_name: geometry_msgs/PoseWithCovariance 
    # offset: 264 size: 344 
    # array_len: 1

    tmp_py_obj = PoseWithCovariance()
    binary_read_recursive_PoseWithCovariance(meta, binary_data, tmp_py_obj, base_off + 264)
    py_obj.pose = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: twist 
    # type_name: geometry_msgs/TwistWithCovariance 
    # offset: 608 size: 336 
    # array_len: 1

    tmp_py_obj = TwistWithCovariance()
    binary_read_recursive_TwistWithCovariance(meta, binary_data, tmp_py_obj, base_off + 608)
    py_obj.twist = tmp_py_obj
    
    return py_obj


def py_to_pdu_Odometry(py_obj: Odometry) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Odometry(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_Odometry(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Odometry):
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
    # member_name: child_frame_id 
    # type_name: string 
    # offset: 136 size: 128 
    # array_len: 1
    type = "string"
    off = 136

    
    bin = binary_io.typeTobin(type, py_obj.child_frame_id)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: pose 
    # type_name: geometry_msgs/PoseWithCovariance 
    # offset: 264 size: 344 
    # array_len: 1
    type = "PoseWithCovariance"
    off = 264

    binary_write_recursive_PoseWithCovariance(parent_off + off, bw_container, allocator, py_obj.pose)
    
    # array_type: single 
    # data_type: struct 
    # member_name: twist 
    # type_name: geometry_msgs/TwistWithCovariance 
    # offset: 608 size: 336 
    # array_len: 1
    type = "TwistWithCovariance"
    off = 608

    binary_write_recursive_TwistWithCovariance(parent_off + off, bw_container, allocator, py_obj.twist)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Odometry <read|write> [args...]")
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
        
        py_obj = pdu_to_py_Odometry(binary_data)
        
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
        
        py_obj = Odometry.from_json(json_str)
        
        binary_data = py_to_pdu_Odometry(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
