
import struct
from .pdu_pytype_HakoCanBody import HakoCanBody
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoCanBody(binary_data: bytes) -> HakoCanBody:
    py_obj = HakoCanBody()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCanBody(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCanBody(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoCanBody, base_off: int):
    # array_type: array 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 0 size: 8 
    # array_len: 8

    
    array_value = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.data = binary_io.binToArrayValues(type, array_value)
    
    return py_obj
