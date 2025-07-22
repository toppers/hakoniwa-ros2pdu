
import struct
from .pdu_pytype_Ev3PduTouchSensor import Ev3PduTouchSensor
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_Ev3PduTouchSensor(binary_data: bytes) -> Ev3PduTouchSensor:
    py_obj = Ev3PduTouchSensor()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Ev3PduTouchSensor(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Ev3PduTouchSensor(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Ev3PduTouchSensor, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: value 
    # type_name: uint32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.value = binary_io.binTovalue("uint32", bin)
    
    return py_obj
