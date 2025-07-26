
import struct
from .pdu_pytype_ImpulseCollision import ImpulseCollision
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_ImpulseCollision(binary_data: bytearray) -> ImpulseCollision:
    py_obj = ImpulseCollision()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ImpulseCollision(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ImpulseCollision(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: ImpulseCollision, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: collision 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.collision = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_target_static 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.is_target_static = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 8 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 8)
    py_obj.restitution_coefficient = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: self_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 16 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 16)
    py_obj.self_contact_vector = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: normal 
    # type_name: geometry_msgs/Vector3 
    # offset: 40 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 40)
    py_obj.normal = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 64 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 64)
    py_obj.target_contact_vector = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 88 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 88)
    py_obj.target_velocity = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_angular_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 112 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 112)
    py_obj.target_angular_velocity = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_euler 
    # type_name: geometry_msgs/Vector3 
    # offset: 136 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 136)
    py_obj.target_euler = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_inertia 
    # type_name: geometry_msgs/Vector3 
    # offset: 160 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 160)
    py_obj.target_inertia = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: target_mass 
    # type_name: float64 
    # offset: 184 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 184, 8)
    py_obj.target_mass = binary_io.binTovalue("float64", bin)
    
    return py_obj


def py_to_pdu_ImpulseCollision(py_obj: ImpulseCollision) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_ImpulseCollision(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_ImpulseCollision(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: ImpulseCollision):
    # array_type: single 
    # data_type: primitive 
    # member_name: collision 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1
    type = "bool"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.collision)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_target_static 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1
    type = "bool"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.is_target_static)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 8 size: 8 
    # array_len: 1
    type = "float64"
    off = 8

    
    bin = binary_io.typeTobin(type, py_obj.restitution_coefficient)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: self_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 16 size: 24 
    # array_len: 1
    type = "Point"
    off = 16

    binary_write_recursive_Point(parent_off + off, bw_container, allocator, py_obj.self_contact_vector)
    
    # array_type: single 
    # data_type: struct 
    # member_name: normal 
    # type_name: geometry_msgs/Vector3 
    # offset: 40 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 40

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.normal)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 64 size: 24 
    # array_len: 1
    type = "Point"
    off = 64

    binary_write_recursive_Point(parent_off + off, bw_container, allocator, py_obj.target_contact_vector)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 88 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 88

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.target_velocity)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_angular_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 112 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 112

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.target_angular_velocity)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_euler 
    # type_name: geometry_msgs/Vector3 
    # offset: 136 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 136

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.target_euler)
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_inertia 
    # type_name: geometry_msgs/Vector3 
    # offset: 160 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 160

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.target_inertia)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: target_mass 
    # type_name: float64 
    # offset: 184 size: 8 
    # array_len: 1
    type = "float64"
    off = 184

    
    bin = binary_io.typeTobin(type, py_obj.target_mass)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_ImpulseCollision <read|write> [args...]")
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
        
        py_obj = pdu_to_py_ImpulseCollision(binary_data)
        
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
        
        py_obj = ImpulseCollision.from_json(json_str)
        
        binary_data = py_to_pdu_ImpulseCollision(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
