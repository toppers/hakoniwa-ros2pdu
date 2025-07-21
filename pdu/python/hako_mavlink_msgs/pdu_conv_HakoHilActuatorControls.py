
import struct
from .pdu_pytype_HakoHilActuatorControls import HakoHilActuatorControls
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilActuatorControls(binary_data: bytes) -> HakoHilActuatorControls:
    py_obj = HakoHilActuatorControls()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilActuatorControls(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilActuatorControls(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoHilActuatorControls, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue(type, bin)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: controls 
    # type_name: float32 
    # offset: 8 size: 64 
    # array_len: 16

    
    array_value = binary_io.readBinary(binary_data, base_off + 8, 64)
    py_obj.controls = binary_io.binToArrayValues(type, array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: mode 
    # type_name: uint8 
    # offset: 72 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 72, 1)
    py_obj.mode = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: flags 
    # type_name: uint64 
    # offset: 80 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 80, 8)
    py_obj.flags = binary_io.binTovalue(type, bin)
    
    return py_obj
