
import struct
from .pdu_pytype_Ev3PduMotor import Ev3PduMotor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Ev3PduMotor(binary_data: bytes) -> Ev3PduMotor:
    py_obj = Ev3PduMotor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduMotor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduMotor(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduMotor, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: power 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.power = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: stop 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.stop = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: reset_angle 
    # type_name: uint32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.reset_angle = binary_io.binTovalue("uint32", bin)
    
    return py_obj
