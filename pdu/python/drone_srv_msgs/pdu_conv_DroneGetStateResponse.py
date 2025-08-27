
import struct
from .pdu_pytype_DroneGetStateResponse import DroneGetStateResponse
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Pose import *
from ..hako_msgs.pdu_conv_HakoBatteryStatus import *



def pdu_to_py_DroneGetStateResponse(binary_data: bytearray) -> DroneGetStateResponse:
    py_obj = DroneGetStateResponse()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DroneGetStateResponse(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DroneGetStateResponse(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: DroneGetStateResponse, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: ok 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.ok = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_ready 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.is_ready = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: current_pose 
    # type_name: geometry_msgs/Pose 
    # offset: 8 size: 56 
    # array_len: 1

    tmp_py_obj = Pose()
    binary_read_recursive_Pose(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.current_pose = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: battery_status 
    # type_name: hako_msgs/HakoBatteryStatus 
    # offset: 64 size: 32 
    # array_len: 1

    tmp_py_obj = HakoBatteryStatus()
    binary_read_recursive_HakoBatteryStatus(meta, binary_data, tmp_py_obj, base_off + 64)
    py_obj.battery_status = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: mode 
    # type_name: string 
    # offset: 96 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 96, 128)
    py_obj.mode = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: message 
    # type_name: string 
    # offset: 224 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 224, 128)
    py_obj.message = binary_io.binTovalue("string", bin)
    
    return py_obj


def py_to_pdu_DroneGetStateResponse(py_obj: DroneGetStateResponse) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_DroneGetStateResponse(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_DroneGetStateResponse(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: DroneGetStateResponse):
    # array_type: single 
    # data_type: primitive 
    # member_name: ok 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1
    type = "bool"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.ok)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_ready 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1
    type = "bool"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.is_ready)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: current_pose 
    # type_name: geometry_msgs/Pose 
    # offset: 8 size: 56 
    # array_len: 1
    type = "Pose"
    off = 8

    binary_write_recursive_Pose(parent_off + off, bw_container, allocator, py_obj.current_pose)
    
    # array_type: single 
    # data_type: struct 
    # member_name: battery_status 
    # type_name: hako_msgs/HakoBatteryStatus 
    # offset: 64 size: 32 
    # array_len: 1
    type = "HakoBatteryStatus"
    off = 64

    binary_write_recursive_HakoBatteryStatus(parent_off + off, bw_container, allocator, py_obj.battery_status)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: mode 
    # type_name: string 
    # offset: 96 size: 128 
    # array_len: 1
    type = "string"
    off = 96

    
    bin = binary_io.typeTobin(type, py_obj.mode)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: message 
    # type_name: string 
    # offset: 224 size: 128 
    # array_len: 1
    type = "string"
    off = 224

    
    bin = binary_io.typeTobin(type, py_obj.message)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_DroneGetStateResponse <read|write> [args...]")
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
        
        py_obj = pdu_to_py_DroneGetStateResponse(binary_data)
        
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
        
        py_obj = DroneGetStateResponse.from_json(json_str)
        
        binary_data = py_to_pdu_DroneGetStateResponse(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
