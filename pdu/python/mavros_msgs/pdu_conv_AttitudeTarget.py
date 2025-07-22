
import struct
from .pdu_pytype_AttitudeTarget import AttitudeTarget
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_Quaternion import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_AttitudeTarget(binary_data: bytes) -> AttitudeTarget:
    py_obj = AttitudeTarget()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AttitudeTarget(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AttitudeTarget(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: AttitudeTarget, base_off: int):
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
