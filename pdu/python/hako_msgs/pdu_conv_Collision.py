
import struct
from .pdu_pytype_Collision import Collision
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Point import *



def pdu_to_py_Collision(binary_data: bytearray) -> Collision:
    py_obj = Collision()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Collision(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Collision(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Collision, base_off: int):
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
    # member_name: contact_num 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.contact_num = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: relative_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.relative_velocity = tmp_py_obj
    
    # array_type: array 
    # data_type: struct 
    # member_name: contact_position 
    # type_name: geometry_msgs/Point 
    # offset: 32 size: 240 
    # array_len: 10

    i = 0
    array_size = 10
    one_elm_size = int(240 / array_size)
    array_value = []
    while i < array_size:
        tmp_py_obj = Point()
        binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 32 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.contact_position = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 272 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 272, 8)
    py_obj.restitution_coefficient = binary_io.binTovalue("float64", bin)
    
    return py_obj


def py_to_pdu_Collision(py_obj: Collision) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Collision(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_Collision(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Collision):
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
    # member_name: contact_num 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1
    type = "uint32"
    off = 4

    
    bin = binary_io.typeTobin(type, py_obj.contact_num)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: relative_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 8 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 8

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.relative_velocity)
    
    # array_type: array 
    # data_type: struct 
    # member_name: contact_position 
    # type_name: geometry_msgs/Point 
    # offset: 32 size: 240 
    # array_len: 10
    type = "Point"
    off = 32

    for i, elm in enumerate(py_obj.contact_position):
        elm_size = 240
        array_size = int(24.0)
        one_elm_size = int(elm_size / array_size)
        binary_write_recursive_Point((parent_off + off + i * one_elm_size), bw_container, allocator, elm)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 272 size: 8 
    # array_len: 1
    type = "float64"
    off = 272

    
    bin = binary_io.typeTobin(type, py_obj.restitution_coefficient)
    bin = get_binary(type, bin, 8)
    allocator.add(bin, expected_offset=parent_off + off)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Collision <read|write> [args...]")
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
        
        py_obj = pdu_to_py_Collision(binary_data)
        
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
        
        py_obj = Collision.from_json(json_str)
        
        binary_data = py_to_pdu_Collision(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
