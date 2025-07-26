
import struct
from .pdu_pytype_DisturbanceWind import DisturbanceWind
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_DisturbanceWind(binary_data: bytearray) -> DisturbanceWind:
    py_obj = DisturbanceWind()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DisturbanceWind(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DisturbanceWind(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: DisturbanceWind, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: value 
    # type_name: geometry_msgs/Vector3 
    # offset: 0 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.value = tmp_py_obj
    
    return py_obj


def py_to_pdu_DisturbanceWind(py_obj: DisturbanceWind) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_DisturbanceWind(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_DisturbanceWind(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: DisturbanceWind):
    # array_type: single 
    # data_type: struct 
    # member_name: value 
    # type_name: geometry_msgs/Vector3 
    # offset: 0 size: 24 
    # array_len: 1
    type = "Vector3"
    off = 0

    binary_write_recursive_Vector3(parent_off + off, bw_container, allocator, py_obj.value)
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_DisturbanceWind <read|write> [args...]")
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
        
        py_obj = pdu_to_py_DisturbanceWind(binary_data)
        
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
        
        py_obj = DisturbanceWind.from_json(json_str)
        
        binary_data = py_to_pdu_DisturbanceWind(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
