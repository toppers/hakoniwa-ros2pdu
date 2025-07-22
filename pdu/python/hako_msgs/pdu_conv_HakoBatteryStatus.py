
import struct
from .pdu_pytype_HakoBatteryStatus import HakoBatteryStatus
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoBatteryStatus(binary_data: bytes) -> HakoBatteryStatus:
    py_obj = HakoBatteryStatus()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoBatteryStatus(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoBatteryStatus(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoBatteryStatus, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: full_voltage 
    # type_name: float64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.full_voltage = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: curr_voltage 
    # type_name: float64 
    # offset: 8 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 8)
    py_obj.curr_voltage = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: curr_temp 
    # type_name: float64 
    # offset: 16 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 8)
    py_obj.curr_temp = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: status 
    # type_name: uint32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.status = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: cycles 
    # type_name: uint32 
    # offset: 28 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 4)
    py_obj.cycles = binary_io.binTovalue("uint32", bin)
    
    return py_obj
