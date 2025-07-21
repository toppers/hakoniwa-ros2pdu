
import struct
from .pdu_pytype_MultiArrayDimension import MultiArrayDimension
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_MultiArrayDimension(binary_data: bytes) -> MultiArrayDimension:
    py_obj = MultiArrayDimension()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_MultiArrayDimension(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_MultiArrayDimension(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: MultiArrayDimension, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: label 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.label = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: size 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.size = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: stride 
    # type_name: uint32 
    # offset: 132 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 4)
    py_obj.stride = binary_io.binTovalue(type, bin)
    
    return py_obj
