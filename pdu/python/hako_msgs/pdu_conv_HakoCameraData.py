
import struct
from .pdu_pytype_HakoCameraData import HakoCameraData
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..sensor_msgs.pdu_conv_CompressedImage import *



def pdu_to_py_HakoCameraData(binary_data: bytes) -> HakoCameraData:
    py_obj = HakoCameraData()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCameraData(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCameraData(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoCameraData, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.request_id = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: image 
    # type_name: sensor_msgs/CompressedImage 
    # offset: 4 size: 272 
    # array_len: 1

    tmp_py_obj = CompressedImage()
    binary_read_recursive_CompressedImage(meta, binary_data, tmp_py_obj, base_off + 4)
    py_obj.image = tmp_py_obj
    
    return py_obj
