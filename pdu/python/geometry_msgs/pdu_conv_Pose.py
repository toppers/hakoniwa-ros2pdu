
import struct
from .pdu_pytype_Pose import Pose
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Quaternion import *



def pdu_to_py_Pose(binary_data: bytes) -> Pose:
    py_obj = Pose()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Pose(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Pose(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Pose, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: position 
    # type_name: Point 
    # offset: 0 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.position = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: orientation 
    # type_name: Quaternion 
    # offset: 24 size: 32 
    # array_len: 1

    tmp_py_obj = Quaternion()
    binary_read_recursive_Quaternion(meta, binary_data, tmp_py_obj, base_off + 24)
    py_obj.orientation = tmp_py_obj
    
    return py_obj
