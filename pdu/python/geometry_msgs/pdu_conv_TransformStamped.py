
import struct
from .pdu_pytype_TransformStamped import TransformStamped
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_Transform import *



def pdu_to_py_TransformStamped(binary_data: bytearray) -> TransformStamped:
    py_obj = TransformStamped()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_TransformStamped(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_TransformStamped(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: TransformStamped, base_off: int):
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
    # member_name: transform 
    # type_name: Transform 
    # offset: 264 size: 56 
    # array_len: 1

    tmp_py_obj = Transform()
    binary_read_recursive_Transform(meta, binary_data, tmp_py_obj, base_off + 264)
    py_obj.transform = tmp_py_obj
    
    return py_obj



def py_to_pduTransformStamped(py_obj: TransformStamped) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_TransformStamped(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_TransformStamped(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: TransformStamped):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: std_msgs/Header 
    # offset: 0 size: 136 
    # array_len: 1
    type = "std_msgs/Header"
    off = 0

    binary_write_recursive_std_msgs/Header(parent_off + off, bw_container, allocator, py_obj.header)
    
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
    # member_name: transform 
    # type_name: Transform 
    # offset: 264 size: 56 
    # array_len: 1
    type = "Transform"
    off = 264

    binary_write_recursive_Transform(parent_off + off, bw_container, allocator, py_obj.transform)
    
