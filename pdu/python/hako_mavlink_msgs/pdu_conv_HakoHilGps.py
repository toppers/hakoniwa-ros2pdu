
import struct
from .pdu_pytype_HakoHilGps import HakoHilGps
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilGps(binary_data: bytes) -> HakoHilGps:
    py_obj = HakoHilGps()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilGps(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilGps(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoHilGps, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue("uint64", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.lat = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.lon = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.alt = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: eph 
    # type_name: uint16 
    # offset: 20 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 2)
    py_obj.eph = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: epv 
    # type_name: uint16 
    # offset: 22 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 22, 2)
    py_obj.epv = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vel 
    # type_name: uint16 
    # offset: 24 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 2)
    py_obj.vel = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vn 
    # type_name: int16 
    # offset: 26 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 26, 2)
    py_obj.vn = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ve 
    # type_name: int16 
    # offset: 28 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 2)
    py_obj.ve = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vd 
    # type_name: int16 
    # offset: 30 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 30, 2)
    py_obj.vd = binary_io.binTovalue("int16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: cog 
    # type_name: uint16 
    # offset: 32 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 2)
    py_obj.cog = binary_io.binTovalue("uint16", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: satellites_visible 
    # type_name: uint8 
    # offset: 34 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 34, 1)
    py_obj.satellites_visible = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 35 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 35, 1)
    py_obj.id = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw 
    # type_name: uint8 
    # offset: 36 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 1)
    py_obj.yaw = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fix_type 
    # type_name: uint8 
    # offset: 37 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 37, 1)
    py_obj.fix_type = binary_io.binTovalue("uint8", bin)
    
    return py_obj
