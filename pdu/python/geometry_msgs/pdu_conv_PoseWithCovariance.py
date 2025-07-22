
import struct
from .pdu_pytype_PoseWithCovariance import PoseWithCovariance
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Pose import *



def pdu_to_py_PoseWithCovariance(binary_data: bytes) -> PoseWithCovariance:
    py_obj = PoseWithCovariance()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_PoseWithCovariance(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_PoseWithCovariance(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: PoseWithCovariance, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: pose 
    # type_name: Pose 
    # offset: 0 size: 56 
    # array_len: 1

    tmp_py_obj = Pose()
    binary_read_recursive_Pose(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.pose = tmp_py_obj
    
    # array_type: array 
    # data_type: primitive 
    # member_name: covariance 
    # type_name: float64 
    # offset: 56 size: 288 
    # array_len: 36

    
    array_value = binary_io.readBinary(binary_data, base_off + 56, 288)
    py_obj.covariance = binary_io.binToArrayValues("float64", array_value)
    
    return py_obj
