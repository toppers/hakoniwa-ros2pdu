
import struct
from .pdu_pytype_Char import Char
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Char(binary_data: bytes) -> Char:
    py_obj = Char()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Char(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Char(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Char, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: data 
    # type_name: char 
    # offset: 0 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 1)
    py_obj.data = binary_io.binTovalue(type, bin)
    
    return py_obj
