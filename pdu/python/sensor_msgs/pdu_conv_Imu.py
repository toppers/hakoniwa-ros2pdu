
import struct
from .pdu_pytype_Imu import Imu
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_Quaternion import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_Imu(binary_data: bytes) -> Imu:
    py_obj = Imu()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Imu(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Imu(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Imu, base_off: int):
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
    # data_type: struct 
    # member_name: orientation 
    # type_name: geometry_msgs/Quaternion 
    # offset: 136 size: 32 
    # array_len: 1

    tmp_py_obj = Quaternion()
    binary_read_recursive_Quaternion(meta, binary_data, tmp_py_obj, base_off + 136)
    py_obj.orientation = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: orientation_covariance 
    # type_name: float64 
    # offset: 168 size: 72 
    # array_len: 9

    
    array_value = binary_io.readBinary(binary_data, base_off + 168, 72)
    py_obj.orientation_covariance = binary_io.binToArrayValues("float64", array_value)
    
    # array_type: single 
    # data_type: struct 
    # member_name: angular_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 240 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 240)
    py_obj.angular_velocity = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: angular_velocity_covariance 
    # type_name: float64 
    # offset: 264 size: 72 
    # array_len: 9

    
    array_value = binary_io.readBinary(binary_data, base_off + 264, 72)
    py_obj.angular_velocity_covariance = binary_io.binToArrayValues("float64", array_value)
    
    # array_type: single 
    # data_type: struct 
    # member_name: linear_acceleration 
    # type_name: geometry_msgs/Vector3 
    # offset: 336 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 336)
    py_obj.linear_acceleration = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: linear_acceleration_covariance 
    # type_name: float64 
    # offset: 360 size: 72 
    # array_len: 9

    
    array_value = binary_io.readBinary(binary_data, base_off + 360, 72)
    py_obj.linear_acceleration_covariance = binary_io.binToArrayValues("float64", array_value)
    
    return py_obj
