
import struct
from .pdu_pytype_HakoStatusMagnetHolder import HakoStatusMagnetHolder
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_HakoStatusMagnetHolder(binary_data: bytes) -> HakoStatusMagnetHolder:
    py_obj = HakoStatusMagnetHolder()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoStatusMagnetHolder(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoStatusMagnetHolder(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoStatusMagnetHolder, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: magnet_on 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.magnet_on = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: contact_on 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.contact_on = binary_io.binTovalue("bool", bin)
    
    return py_obj
