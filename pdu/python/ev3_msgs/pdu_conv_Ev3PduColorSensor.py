
import struct
from .pdu_pytype_Ev3PduColorSensor import Ev3PduColorSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Ev3PduColorSensor(binary_data: bytes) -> Ev3PduColorSensor:
    py_obj = Ev3PduColorSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduColorSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduColorSensor(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduColorSensor, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: color 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.color = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: reflect 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.reflect = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rgb_r 
    # type_name: uint32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.rgb_r = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rgb_g 
    # type_name: uint32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.rgb_g = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rgb_b 
    # type_name: uint32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.rgb_b = binary_io.binTovalue("uint32", bin)
    
    return py_obj
