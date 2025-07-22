
import struct
from .pdu_pytype_HakoHeartbeat import HakoHeartbeat
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHeartbeat(binary_data: bytes) -> HakoHeartbeat:
    py_obj = HakoHeartbeat()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHeartbeat(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHeartbeat(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoHeartbeat, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: type 
    # type_name: uint8 
    # offset: 0 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 1)
    py_obj.type = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: autopilot 
    # type_name: uint8 
    # offset: 1 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 1, 1)
    py_obj.autopilot = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: base_mode 
    # type_name: uint8 
    # offset: 2 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 2, 1)
    py_obj.base_mode = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: custom_mode 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.custom_mode = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: system_status 
    # type_name: uint8 
    # offset: 8 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 1)
    py_obj.system_status = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: mavlink_version 
    # type_name: uint8 
    # offset: 9 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 9, 1)
    py_obj.mavlink_version = binary_io.binTovalue("uint8", bin)
    
    return py_obj
