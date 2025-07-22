
import struct
from .pdu_pytype_HakoSERVO_OUTPUT_RAW import HakoSERVO_OUTPUT_RAW
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoSERVO_OUTPUT_RAW(binary_data: bytes) -> HakoSERVO_OUTPUT_RAW:
    py_obj = HakoSERVO_OUTPUT_RAW()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoSERVO_OUTPUT_RAW, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.time_usec = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: port 
    # type_name: uint8 
    # offset: 4 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 1)
    py_obj.port = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo1_raw 
    # type_name: uint16 
    # offset: 6 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 6, 2)
    py_obj.servo1_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo2_raw 
    # type_name: uint16 
    # offset: 8 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 2)
    py_obj.servo2_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo3_raw 
    # type_name: uint16 
    # offset: 10 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 10, 2)
    py_obj.servo3_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo4_raw 
    # type_name: uint16 
    # offset: 12 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 2)
    py_obj.servo4_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo5_raw 
    # type_name: uint16 
    # offset: 14 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 14, 2)
    py_obj.servo5_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo6_raw 
    # type_name: uint16 
    # offset: 16 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 2)
    py_obj.servo6_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo7_raw 
    # type_name: uint16 
    # offset: 18 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 18, 2)
    py_obj.servo7_raw = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: servo8_raw 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.servo8_raw = binary_io.binTovalue("uint16", bin)
    
    return py_obj
