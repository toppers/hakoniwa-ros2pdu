
import struct
from .pdu_pytype_Ev3PduSensorHeader import Ev3PduSensorHeader
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Ev3PduSensorHeader(binary_data: bytes) -> Ev3PduSensorHeader:
    py_obj = Ev3PduSensorHeader()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduSensorHeader(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduSensorHeader(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduSensorHeader, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.name = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: version 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.version = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: hakoniwa_time 
    # type_name: int64 
    # offset: 136 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 8)
    py_obj.hakoniwa_time = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_off 
    # type_name: uint32 
    # offset: 144 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 4)
    py_obj.ext_off = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: ext_size 
    # type_name: uint32 
    # offset: 148 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 148, 4)
    py_obj.ext_size = binary_io.binTovalue(type, bin)
    
    return py_obj
