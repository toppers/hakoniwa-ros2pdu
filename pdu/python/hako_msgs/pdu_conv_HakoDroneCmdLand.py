
import struct
from .pdu_pytype_HakoDroneCmdLand import HakoDroneCmdLand
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_HakoDroneCmdHeader import *



def pdu_to_py_HakoDroneCmdLand(binary_data: bytes) -> HakoDroneCmdLand:
    py_obj = HakoDroneCmdLand()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoDroneCmdLand(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoDroneCmdLand(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoDroneCmdLand, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: HakoDroneCmdHeader 
    # offset: 0 size: 12 
    # array_len: 1

    tmp_py_obj = HakoDroneCmdHeader()
    binary_read_recursive_HakoDroneCmdHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: height 
    # type_name: float64 
    # offset: 16 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 8)
    py_obj.height = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: speed 
    # type_name: float64 
    # offset: 24 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 8)
    py_obj.speed = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw_deg 
    # type_name: float64 
    # offset: 32 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 8)
    py_obj.yaw_deg = binary_io.binTovalue("float64", bin)
    
    return py_obj
