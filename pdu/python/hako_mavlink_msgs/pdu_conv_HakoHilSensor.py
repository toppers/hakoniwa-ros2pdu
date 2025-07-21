
import struct
from .pdu_pytype_HakoHilSensor import HakoHilSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilSensor(binary_data: bytes) -> HakoHilSensor:
    py_obj = HakoHilSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilSensor(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoHilSensor, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: time_usec 
    # type_name: uint64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.time_usec = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: float32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.xacc = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: float32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.yacc = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: float32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.zacc = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xgyro 
    # type_name: float32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.xgyro = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ygyro 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.ygyro = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zgyro 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 4)
    py_obj.zgyro = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xmag 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 4)
    py_obj.xmag = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ymag 
    # type_name: float32 
    # offset: 36 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 4)
    py_obj.ymag = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zmag 
    # type_name: float32 
    # offset: 40 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 40, 4)
    py_obj.zmag = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: abs_pressure 
    # type_name: float32 
    # offset: 44 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 44, 4)
    py_obj.abs_pressure = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: diff_pressure 
    # type_name: float32 
    # offset: 48 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 48, 4)
    py_obj.diff_pressure = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pressure_alt 
    # type_name: float32 
    # offset: 52 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 52, 4)
    py_obj.pressure_alt = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: temperature 
    # type_name: float32 
    # offset: 56 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 56, 4)
    py_obj.temperature = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: fields_updated 
    # type_name: uint32 
    # offset: 60 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 60, 4)
    py_obj.fields_updated = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: id 
    # type_name: uint8 
    # offset: 64 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 64, 1)
    py_obj.id = binary_io.binTovalue(type, bin)
    
    return py_obj
