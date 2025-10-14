
import struct
from .pdu_pytype_Disturbance import Disturbance
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_DisturbanceTemperature import *
from ..hako_msgs.pdu_conv_DisturbanceWind import *
from ..hako_msgs.pdu_conv_DisturbanceAtm import *
from ..hako_msgs.pdu_conv_DisturbanceBoundary import *
from ..hako_msgs.pdu_conv_DisturbanceUserCustom import *



def pdu_to_py_Disturbance(binary_data: bytearray) -> Disturbance:
    py_obj = Disturbance()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Disturbance(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Disturbance(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: Disturbance, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: d_temp 
    # type_name: hako_msgs/DisturbanceTemperature 
    # offset: 0 size: 8 
    # array_len: 1

    tmp_py_obj = DisturbanceTemperature()
    binary_read_recursive_DisturbanceTemperature(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.d_temp = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_wind 
    # type_name: hako_msgs/DisturbanceWind 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = DisturbanceWind()
    binary_read_recursive_DisturbanceWind(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.d_wind = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_atm 
    # type_name: hako_msgs/DisturbanceAtm 
    # offset: 32 size: 8 
    # array_len: 1

    tmp_py_obj = DisturbanceAtm()
    binary_read_recursive_DisturbanceAtm(meta, binary_data, tmp_py_obj, base_off + 32)
    py_obj.d_atm = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_boundary 
    # type_name: hako_msgs/DisturbanceBoundary 
    # offset: 40 size: 48 
    # array_len: 1

    tmp_py_obj = DisturbanceBoundary()
    binary_read_recursive_DisturbanceBoundary(meta, binary_data, tmp_py_obj, base_off + 40)
    py_obj.d_boundary = tmp_py_obj
    
    # array_type: varray 
    # data_type: struct 
    # member_name: d_user_custom 
    # type_name: hako_msgs/DisturbanceUserCustom 
    # offset: 88 size: 8 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 88, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 88 + 4, 4))
    one_elm_size = 8
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = DisturbanceUserCustom()
        binary_read_recursive_DisturbanceUserCustom(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.d_user_custom = array_value    
    
    return py_obj


def py_to_pdu_Disturbance(py_obj: Disturbance) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_Disturbance(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_Disturbance(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: Disturbance):
    # array_type: single 
    # data_type: struct 
    # member_name: d_temp 
    # type_name: hako_msgs/DisturbanceTemperature 
    # offset: 0 size: 8 
    # array_len: 1
    type = "DisturbanceTemperature"
    off = 0

    binary_write_recursive_DisturbanceTemperature(parent_off + off, bw_container, allocator, py_obj.d_temp)
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_wind 
    # type_name: hako_msgs/DisturbanceWind 
    # offset: 8 size: 24 
    # array_len: 1
    type = "DisturbanceWind"
    off = 8

    binary_write_recursive_DisturbanceWind(parent_off + off, bw_container, allocator, py_obj.d_wind)
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_atm 
    # type_name: hako_msgs/DisturbanceAtm 
    # offset: 32 size: 8 
    # array_len: 1
    type = "DisturbanceAtm"
    off = 32

    binary_write_recursive_DisturbanceAtm(parent_off + off, bw_container, allocator, py_obj.d_atm)
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_boundary 
    # type_name: hako_msgs/DisturbanceBoundary 
    # offset: 40 size: 48 
    # array_len: 1
    type = "DisturbanceBoundary"
    off = 40

    binary_write_recursive_DisturbanceBoundary(parent_off + off, bw_container, allocator, py_obj.d_boundary)
    
    # array_type: varray 
    # data_type: struct 
    # member_name: d_user_custom 
    # type_name: hako_msgs/DisturbanceUserCustom 
    # offset: 88 size: 8 
    # array_len: 8
    type = "DisturbanceUserCustom"
    off = 88

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.d_user_custom)
    for i, elm in enumerate(py_obj.d_user_custom):
        one_elm_size =  8
        binary_write_recursive_DisturbanceUserCustom((parent_off + i * one_elm_size), bw_container, bw_container.heap_allocator, elm)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)    
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_Disturbance <read|write> [args...]")
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
        
        py_obj = pdu_to_py_Disturbance(binary_data)
        
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
        
        py_obj = Disturbance.from_json(json_str)
        
        binary_data = py_to_pdu_Disturbance(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
