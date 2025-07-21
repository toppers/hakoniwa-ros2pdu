
import struct
from .pdu_pytype_ServiceRequestHeader import ServiceRequestHeader
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_ServiceRequestHeader(binary_data: bytes) -> ServiceRequestHeader:
    py_obj = ServiceRequestHeader()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ServiceRequestHeader(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ServiceRequestHeader(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: ServiceRequestHeader, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.request_id = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: service_name 
    # type_name: string 
    # offset: 4 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 128)
    py_obj.service_name = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: client_name 
    # type_name: string 
    # offset: 132 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 128)
    py_obj.client_name = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: opcode 
    # type_name: uint8 
    # offset: 260 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 260, 1)
    py_obj.opcode = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: status_poll_interval_msec 
    # type_name: int32 
    # offset: 264 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 264, 4)
    py_obj.status_poll_interval_msec = binary_io.binTovalue(type, bin)
    
    return py_obj
