
import struct
from .pdu_pytype_HakoHilStateQuaternion import HakoHilStateQuaternion
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoHilStateQuaternion(binary_data: bytes) -> HakoHilStateQuaternion:
    py_obj = HakoHilStateQuaternion()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoHilStateQuaternion(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoHilStateQuaternion(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoHilStateQuaternion, base_off: int):
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
    # member_name: attitude_quaternion 
    # type_name: float32 
    # offset: 8 size: 16 
    # array_len: 4

    
    array_value = binary_io.readBinary(binary_data, base_off + 8, 16)
    py_obj.attitude_quaternion = binary_io.binToArrayValues(type, array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rollspeed 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.rollspeed = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pitchspeed 
    # type_name: float32 
    # offset: 28 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 28, 4)
    py_obj.pitchspeed = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yawspeed 
    # type_name: float32 
    # offset: 32 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 32, 4)
    py_obj.yawspeed = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lat 
    # type_name: int32 
    # offset: 36 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 36, 4)
    py_obj.lat = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: lon 
    # type_name: int32 
    # offset: 40 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 40, 4)
    py_obj.lon = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: alt 
    # type_name: int32 
    # offset: 44 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 44, 4)
    py_obj.alt = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vx 
    # type_name: int16 
    # offset: 48 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 48, 2)
    py_obj.vx = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vy 
    # type_name: int16 
    # offset: 50 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 50, 2)
    py_obj.vy = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: vz 
    # type_name: int16 
    # offset: 52 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 52, 2)
    py_obj.vz = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ind_airspeed 
    # type_name: uint16 
    # offset: 54 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 54, 2)
    py_obj.ind_airspeed = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: true_airspeed 
    # type_name: uint16 
    # offset: 56 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 56, 2)
    py_obj.true_airspeed = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: xacc 
    # type_name: int16 
    # offset: 58 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 58, 2)
    py_obj.xacc = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yacc 
    # type_name: int16 
    # offset: 60 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 60, 2)
    py_obj.yacc = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: zacc 
    # type_name: int16 
    # offset: 62 size: 2 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 62, 2)
    py_obj.zacc = binary_io.binTovalue(type, bin)
    
    return py_obj
