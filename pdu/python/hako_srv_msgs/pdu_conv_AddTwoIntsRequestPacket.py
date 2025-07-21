
import struct
from .pdu_pytype_AddTwoIntsRequestPacket import AddTwoIntsRequestPacket
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_srv_msgs.pdu_conv_ServiceRequestHeader import *
from ..hako_srv_msgs.pdu_conv_AddTwoIntsRequest import *



def pdu_to_py_AddTwoIntsRequestPacket(binary_data: bytes) -> AddTwoIntsRequestPacket:
    py_obj = AddTwoIntsRequestPacket()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AddTwoIntsRequestPacket(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AddTwoIntsRequestPacket(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: AddTwoIntsRequestPacket, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: ServiceRequestHeader 
    # offset: 0 size: 268 
    # array_len: 1

    tmp_py_obj = ServiceRequestHeader()
    binary_read_recursive_ServiceRequestHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: AddTwoIntsRequest 
    # offset: 272 size: 16 
    # array_len: 1

    tmp_py_obj = AddTwoIntsRequest()
    binary_read_recursive_AddTwoIntsRequest(meta, binary_data, tmp_py_obj, base_off + 272)
    py_obj.body = tmp_py_obj
    
    return py_obj
