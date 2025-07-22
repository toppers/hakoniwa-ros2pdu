
import struct
from .pdu_pytype_SimTime import SimTime
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_SimTime(binary_data: bytes) -> SimTime:
    py_obj = SimTime()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_SimTime(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_SimTime(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: SimTime, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue("uint64", bin)
    
    return py_obj
