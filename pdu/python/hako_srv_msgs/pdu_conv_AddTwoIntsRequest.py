
import struct
from .pdu_pytype_AddTwoIntsRequest import AddTwoIntsRequest
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_AddTwoIntsRequest(binary_data: bytes) -> AddTwoIntsRequest:
    py_obj = AddTwoIntsRequest()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AddTwoIntsRequest(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AddTwoIntsRequest(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: AddTwoIntsRequest, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: a 
    # type_name: int64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.a = binary_io.binTovalue("int64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: b 
    # type_name: int64 
    # offset: 8 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 8)
    py_obj.b = binary_io.binTovalue("int64", bin)
    
    return py_obj
