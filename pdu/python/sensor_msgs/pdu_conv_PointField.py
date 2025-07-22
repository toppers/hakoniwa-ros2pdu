
import struct
from .pdu_pytype_PointField import PointField
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_PointField(binary_data: bytes) -> PointField:
    py_obj = PointField()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_PointField(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_PointField(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: PointField, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: offset 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.offset = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: datatype 
    # type_name: uint8 
    # offset: 132 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 1)
    py_obj.datatype = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: count 
    # type_name: uint32 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.count = binary_io.binTovalue("uint32", bin)
    
    return py_obj
