
import struct
from .pdu_pytype_AttitudeTarget import AttitudeTarget
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_Quaternion import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_AttitudeTarget(binary_data: bytearray) -> AttitudeTarget:
    py_obj = AttitudeTarget()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AttitudeTarget(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AttitudeTarget(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: AttitudeTarget, base_off: int):
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
    # member_name: type_mask 
    # type_name: uint8 
    # offset: 136 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 1)
    py_obj.type_mask = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: orientation 
    # type_name: geometry_msgs/Quaternion 
    # offset: 144 size: 32 
    # array_len: 1

    tmp_py_obj = Quaternion()
    binary_read_recursive_Quaternion(meta, binary_data, tmp_py_obj, base_off + 144)
    py_obj.orientation = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body_rate 
    # type_name: geometry_msgs/Vector3 
    # offset: 176 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 176)
    py_obj.body_rate = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: thrust 
    # type_name: float32 
    # offset: 200 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 200, 4)
    py_obj.thrust = binary_io.binTovalue("float32", bin)
    
    return py_obj



def py_to_pduAttitudeTarget(py_obj: AttitudeTarget) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_AttitudeTarget(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_AttitudeTarget(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: AttitudeTarget):
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
    # member_name: type_mask 
    # type_name: uint8 
    # offset: 136 size: 1 
    # array_len: 1
    type = "uint8"
    off = 136

    
    bin = binary_io.typeTobin(type, py_obj.type_mask)
    bin = get_binary(type, bin, 1)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: struct 
    # member_name: orientation 
    # type_name: geometry_msgs/Quaternion 
    # offset: 144 size: 32 
    # array_len: 1
    type = "geometry_msgs/Quaternion"
    off = 144

    binary_write_recursive_geometry_msgs/Quaternion(parent_off + off, bw_container, allocator, py_obj.orientation)
    
    # array_type: single 
    # data_type: struct 
    # member_name: body_rate 
    # type_name: geometry_msgs/Vector3 
    # offset: 176 size: 24 
    # array_len: 1
    type = "geometry_msgs/Vector3"
    off = 176

    binary_write_recursive_geometry_msgs/Vector3(parent_off + off, bw_container, allocator, py_obj.body_rate)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: thrust 
    # type_name: float32 
    # offset: 200 size: 4 
    # array_len: 1
    type = "float32"
    off = 200

    
    bin = binary_io.typeTobin(type, py_obj.thrust)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
