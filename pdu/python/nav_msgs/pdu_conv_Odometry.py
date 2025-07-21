
import struct
from .pdu_pytype_Odometry import Odometry
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..geometry_msgs.pdu_conv_PoseWithCovariance import *
from ..geometry_msgs.pdu_conv_TwistWithCovariance import *



def pdu_to_py_Odometry(binary_data: bytes) -> Odometry:
    py_obj = Odometry()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Odometry(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Odometry(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Odometry, base_off: int):
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
    py_obj.child_frame_id = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: pose 
    # type_name: geometry_msgs/PoseWithCovariance 
    # offset: 264 size: 344 
    # array_len: 1

    tmp_py_obj = PoseWithCovariance()
    binary_read_recursive_PoseWithCovariance(meta, binary_data, tmp_py_obj, base_off + 264)
    py_obj.pose = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: twist 
    # type_name: geometry_msgs/TwistWithCovariance 
    # offset: 608 size: 336 
    # array_len: 1

    tmp_py_obj = TwistWithCovariance()
    binary_read_recursive_TwistWithCovariance(meta, binary_data, tmp_py_obj, base_off + 608)
    py_obj.twist = tmp_py_obj
    
    return py_obj
