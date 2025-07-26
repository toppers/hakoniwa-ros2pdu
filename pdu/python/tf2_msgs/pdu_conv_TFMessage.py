
import struct
from .pdu_pytype_TFMessage import TFMessage
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_TransformStamped import *



def pdu_to_py_TFMessage(binary_data: bytearray) -> TFMessage:
    py_obj = TFMessage()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_TFMessage(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_TFMessage(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: TFMessage, base_off: int):
    # array_type: varray 
    # data_type: struct 
    # member_name: transforms 
    # type_name: geometry_msgs/TransformStamped 
    # offset: 0 size: 320 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0 + 4, 4))
    one_elm_size = 320
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = TransformStamped()
        binary_read_recursive_TransformStamped(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.transforms = array_value    
    
    return py_obj


def py_to_pdu_TFMessage(py_obj: TFMessage) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_TFMessage(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_TFMessage(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: TFMessage):
    # array_type: varray 
    # data_type: struct 
    # member_name: transforms 
    # type_name: geometry_msgs/TransformStamped 
    # offset: 0 size: 320 
    # array_len: 8
    type = "TransformStamped"
    off = 0

    offset_from_heap = bw_container.heap_allocator.size()
    array_size = len(py_obj.transforms)
    for i, elm in enumerate(py_obj.transforms):
        one_elm_size =  320
        binary_write_recursive_TransformStamped((parent_off + i * one_elm_size), bw_container, bw_container.heap_allocator, elm)
    a_b = array_size.to_bytes(4, byteorder='little')
    o_b = offset_from_heap.to_bytes(4, byteorder='little')
    allocator.add(a_b + o_b, expected_offset=parent_off + off)    
    

if __name__ == "__main__":
    import sys
    import json

    def print_usage():
        print(f"Usage: python -m pdu.python.pdu_conv_TFMessage <read|write> [args...]")
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
        
        py_obj = pdu_to_py_TFMessage(binary_data)
        
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
        
        py_obj = TFMessage.from_json(json_str)
        
        binary_data = py_to_pdu_TFMessage(py_obj)

        with open(output_binary_filepath, "wb") as f:
            f.write(binary_data)

    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)
