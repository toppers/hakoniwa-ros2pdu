
import struct
from .pdu_pytype_AddTwoIntsResponsePacket import AddTwoIntsResponsePacket
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_srv_msgs.pdu_conv_ServiceResponseHeader import *
from ..hako_srv_msgs.pdu_conv_AddTwoIntsResponse import *



def pdu_to_py_AddTwoIntsResponsePacket(binary_data: bytes) -> AddTwoIntsResponsePacket:
    py_obj = AddTwoIntsResponsePacket()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AddTwoIntsResponsePacket(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AddTwoIntsResponsePacket(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: AddTwoIntsResponsePacket, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: ServiceResponseHeader 
    # offset: 0 size: 268 
    # array_len: 1

    tmp_py_obj = ServiceResponseHeader()
    binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: AddTwoIntsResponse 
    # offset: 272 size: 8 
    # array_len: 1

    tmp_py_obj = AddTwoIntsResponse()
    binary_read_recursive_AddTwoIntsResponse(meta, binary_data, tmp_py_obj, base_off + 272)
    py_obj.body = tmp_py_obj
    
    return py_obj
