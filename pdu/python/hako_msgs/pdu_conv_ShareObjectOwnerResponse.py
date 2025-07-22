
import struct
from .pdu_pytype_ShareObjectOwnerResponse import ShareObjectOwnerResponse
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_ShareObjectOwnerResponse(binary_data: bytes) -> ShareObjectOwnerResponse:
    py_obj = ShareObjectOwnerResponse()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ShareObjectOwnerResponse(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ShareObjectOwnerResponse(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: ShareObjectOwnerResponse, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: object_name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.object_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: request_type 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.request_type = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: owner_id 
    # type_name: uint32 
    # offset: 132 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 4)
    py_obj.owner_id = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: accepted 
    # type_name: bool 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.accepted = binary_io.binTovalue("bool", bin)
    
    return py_obj
