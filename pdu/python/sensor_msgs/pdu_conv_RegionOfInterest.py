
import struct
from .pdu_pytype_RegionOfInterest import RegionOfInterest
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_RegionOfInterest(binary_data: bytes) -> RegionOfInterest:
    py_obj = RegionOfInterest()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_RegionOfInterest(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_RegionOfInterest(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: RegionOfInterest, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: x_offset 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.x_offset = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: y_offset 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.y_offset = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: height 
    # type_name: uint32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.height = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.width = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: do_rectify 
    # type_name: bool 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.do_rectify = binary_io.binTovalue("bool", bin)
    
    return py_obj
