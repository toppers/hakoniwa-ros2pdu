
import struct
from .pdu_pytype_DroneGoToRequest import DroneGoToRequest
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_DroneGoToRequest(binary_data: bytearray) -> DroneGoToRequest:
    py_obj = DroneGoToRequest()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DroneGoToRequest(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DroneGoToRequest(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: DroneGoToRequest, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: drone_name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.drone_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_pose 
    # type_name: geometry_msgs/Vector3 
    # offset: 128 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 128)
    py_obj.target_pose = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: speed_m_s 
    # type_name: float32 
    # offset: 152 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 152, 4)
    py_obj.speed_m_s = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_deg 
    # type_name: float32 
    # offset: 156 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 156, 4)
    py_obj.yaw_deg = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: tolerance_m 
    # type_name: float32 
    # offset: 160 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 160, 4)
    py_obj.tolerance_m = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: timeout_sec 
    # type_name: float32 
    # offset: 164 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 164, 4)
    py_obj.timeout_sec = binary_io.binTovalue("float32", bin)
    
    return py_obj


def py_to_pdu_DroneGoToRequest(py_obj: DroneGoToRequest) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_DroneGoToRequest(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_DroneGoToRequest(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: DroneGoToRequest):
    # array_type: single 
    # data_type: primitive 
    # member_name: drone_name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1
    type = "string"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.drone_name)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_pose 
    # type_name: geometry_msgs/Vector3 
    # offset: 128 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 128

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.target_pose)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: speed_m_s 
    # type_name: float32 
    # offset: 152 size: 4 
    # array_len: 1
    type = "float32"
    off = 152

    
    bin = binary_io.typeTobin(type, py_obj.speed_m_s)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_deg 
    # type_name: float32 
    # offset: 156 size: 4 
    # array_len: 1
    type = "float32"
    off = 156

    
    bin = binary_io.typeTobin(type, py_obj.yaw_deg)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: tolerance_m 
    # type_name: float32 
    # offset: 160 size: 4 
    # array_len: 1
    type = "float32"
    off = 160

    
    bin = binary_io.typeTobin(type, py_obj.tolerance_m)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: timeout_sec 
    # type_name: float32 
    # offset: 164 size: 4 
    # array_len: 1
    type = "float32"
    off = 164

    
    bin = binary_io.typeTobin(type, py_obj.timeout_sec)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_DroneGoToRequest <read|write> [args...]")
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
        
        py_obj = pdu_to_py_DroneGoToRequest(binary_data)
        
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
        
        py_obj = DroneGoToRequest.from_json(json_str)
        
        binary_data = py_to_pdu_DroneGoToRequest(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
