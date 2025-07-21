
import struct
from .pdu_pytype_DisturbanceTemperature import DisturbanceTemperature
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_DisturbanceTemperature(binary_data: bytes) -> DisturbanceTemperature:
    py_obj = DisturbanceTemperature()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DisturbanceTemperature(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DisturbanceTemperature(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: DisturbanceTemperature, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: value 
    # type_name: float64 
    # offset: 0 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 8)
    py_obj.value = binary_io.binTovalue(type, bin)
    
    return py_obj
