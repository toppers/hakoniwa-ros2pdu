
import struct
from .pdu_pytype_HakoATTITUDE import HakoATTITUDE
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoATTITUDE(binary_data: bytes) -> HakoATTITUDE:
    py_obj = HakoATTITUDE()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoATTITUDE(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoATTITUDE(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoATTITUDE, base_off: int):
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
    # member_name: roll 
    # type_name: float32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.roll = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pitch 
    # type_name: float32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.pitch = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yaw 
    # type_name: float32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.yaw = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: rollspeed 
    # type_name: float32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.rollspeed = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: pitchspeed 
    # type_name: float32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.pitchspeed = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: yawspeed 
    # type_name: float32 
    # offset: 24 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 24, 4)
    py_obj.yawspeed = binary_io.binTovalue("float32", bin)
    
    return py_obj
