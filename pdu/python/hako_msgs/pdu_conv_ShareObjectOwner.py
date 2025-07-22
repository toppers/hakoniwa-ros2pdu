
import struct
from .pdu_pytype_ShareObjectOwner import ShareObjectOwner
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Twist import *



def pdu_to_py_ShareObjectOwner(binary_data: bytes) -> ShareObjectOwner:
    py_obj = ShareObjectOwner()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ShareObjectOwner(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ShareObjectOwner(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: ShareObjectOwner, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: object_name 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.object_name = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: owner_id 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.owner_id = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: last_update 
    # type_name: uint64 
    # offset: 136 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 8)
    py_obj.last_update = binary_io.binTovalue("uint64", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: pos 
    # type_name: geometry_msgs/Twist 
    # offset: 144 size: 48 
    # array_len: 1

    tmp_py_obj = Twist()
    binary_read_recursive_Twist(meta, binary_data, tmp_py_obj, base_off + 144)
    py_obj.pos = tmp_py_obj
    
    return py_obj
