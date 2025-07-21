
import struct
from .pdu_pytype_Header import Header
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..builtin_interfaces.pdu_conv_Time import *



def pdu_to_py_Header(binary_data: bytes) -> Header:
    py_obj = Header()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Header(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Header(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Header, base_off):
    # array_type: single 
    # data_type: struct 
    # member_name: stamp 
    # type_name: builtin_interfaces/Time 
    # offset: 0 size: 8 
    # array_len: 1

    tmp_py_obj = Time()
    binary_read_recursive_Time(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.stamp = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: frame_id 
    # type_name: string 
    # offset: 8 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 128)
    py_obj.frame_id = binary_io.binTovalue(type, bin)
    
    return py_obj
