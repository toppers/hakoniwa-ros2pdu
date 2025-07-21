
import struct
from .pdu_pytype_HakoCameraInfo import HakoCameraInfo
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_HakoCameraInfo(binary_data: bytes) -> HakoCameraInfo:
    py_obj = HakoCameraInfo()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCameraInfo(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCameraInfo(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoCameraInfo, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.request_id = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: angle 
    # type_name: geometry_msgs/Vector3 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.angle = tmp_py_obj
    
    return py_obj
