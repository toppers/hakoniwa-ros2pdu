
import struct
from .pdu_pytype_UInt16 import UInt16
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_UInt16(binary_data: bytes) -> UInt16:
    py_obj = UInt16()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_UInt16(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_UInt16(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: UInt16, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint16 
    # offset: 0 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 2)
    py_obj.data = binary_io.binTovalue(type, bin)
    
    return py_obj
