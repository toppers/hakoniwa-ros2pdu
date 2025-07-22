
import struct
from .pdu_pytype_HakoGLOBAL_POSITION_INT import HakoGLOBAL_POSITION_INT
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoGLOBAL_POSITION_INT(binary_data: bytes) -> HakoGLOBAL_POSITION_INT:
    py_obj = HakoGLOBAL_POSITION_INT()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoGLOBAL_POSITION_INT(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoGLOBAL_POSITION_INT(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoGLOBAL_POSITION_INT, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_boot_ms 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.time_boot_ms = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.lat = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.lon = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: relative_alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.relative_alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.vx = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 22 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 22, 2)
    py_obj.vy = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 24 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 2)
    py_obj.vz = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hdg 
    # type_name: uint16 
    # offset: 26 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 26, 2)
    py_obj.hdg = binary_io.binTovalue("uint16", bin)
    
    return py_obj
