
import struct
from .pdu_pytype_Image import Image
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *



def pdu_to_py_Image(binary_data: bytes) -> Image:
    py_obj = Image()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Image(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Image(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Image, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: std_msgs/Header 
    # offset: 0 size: 136 
    # array_len: 1

    tmp_py_obj = Header()
    binary_read_recursive_Header(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: height 
    # type_name: uint32 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.height = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 140 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 140, 4)
    py_obj.width = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encoding 
    # type_name: string 
    # offset: 144 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 128)
    py_obj.encoding = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: uint8 
    # offset: 272 size: 1 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 272, 1)
    py_obj.is_bigendian = binary_io.binTovalue("uint8", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: step 
    # type_name: uint32 
    # offset: 276 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 276, 4)
    py_obj.step = binary_io.binTovalue("uint32", bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 280 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 280, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 280 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    return py_obj
