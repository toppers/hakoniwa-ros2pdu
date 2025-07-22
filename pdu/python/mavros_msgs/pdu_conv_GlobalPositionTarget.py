
import struct
from .pdu_pytype_GlobalPositionTarget import GlobalPositionTarget
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_GlobalPositionTarget(binary_data: bytes) -> GlobalPositionTarget:
    py_obj = GlobalPositionTarget()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_GlobalPositionTarget(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_GlobalPositionTarget(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: GlobalPositionTarget, base_off: int):
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
    # member_name: coordinate_frame 
    # type_name: uint8 
    # offset: 136 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 1)
    py_obj.coordinate_frame = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: type_mask 
    # type_name: uint16 
    # offset: 138 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 138, 2)
    py_obj.type_mask = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: latitude 
    # type_name: float64 
    # offset: 144 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 8)
    py_obj.latitude = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: longitude 
    # type_name: float64 
    # offset: 152 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 152, 8)
    py_obj.longitude = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: altitude 
    # type_name: float32 
    # offset: 160 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 160, 4)
    py_obj.altitude = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 168 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 168)
    py_obj.velocity = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: acceleration_or_force 
    # type_name: geometry_msgs/Vector3 
    # offset: 192 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 192)
    py_obj.acceleration_or_force = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw 
    # type_name: float32 
    # offset: 216 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 216, 4)
    py_obj.yaw = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_rate 
    # type_name: float32 
    # offset: 220 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 220, 4)
    py_obj.yaw_rate = binary_io.binTovalue("float32", bin)
    
    return py_obj
