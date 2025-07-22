
import struct
from .pdu_pytype_ServiceResponseHeader import ServiceResponseHeader
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_ServiceResponseHeader(binary_data: bytes) -> ServiceResponseHeader:
    py_obj = ServiceResponseHeader()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ServiceResponseHeader(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ServiceResponseHeader(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: ServiceResponseHeader, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.request_id = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: service_name 
    # type_name: string 
    # offset: 4 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 128)
    py_obj.service_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: client_name 
    # type_name: string 
    # offset: 132 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 128)
    py_obj.client_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: status 
    # type_name: uint8 
    # offset: 260 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 260, 1)
    py_obj.status = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: processing_percentage 
    # type_name: uint8 
    # offset: 261 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 261, 1)
    py_obj.processing_percentage = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: result_code 
    # type_name: int32 
    # offset: 264 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 264, 4)
    py_obj.result_code = binary_io.binTovalue("int32", bin)
    
    return py_obj
