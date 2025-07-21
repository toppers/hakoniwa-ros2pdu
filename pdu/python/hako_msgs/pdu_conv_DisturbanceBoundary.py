
import struct
from .pdu_pytype_DisturbanceBoundary import DisturbanceBoundary
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_DisturbanceBoundary(binary_data: bytes) -> DisturbanceBoundary:
    py_obj = DisturbanceBoundary()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DisturbanceBoundary(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DisturbanceBoundary(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: DisturbanceBoundary, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: boundary_point 
    # type_name: geometry_msgs/Point 
    # offset: 0 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.boundary_point = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: boundary_normal 
    # type_name: geometry_msgs/Vector3 
    # offset: 24 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 24)
    py_obj.boundary_normal = tmp_py_obj
    
    return py_obj
