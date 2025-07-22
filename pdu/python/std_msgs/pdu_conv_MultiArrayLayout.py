
import struct
from .pdu_pytype_MultiArrayLayout import MultiArrayLayout
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_MultiArrayDimension import *



def pdu_to_py_MultiArrayLayout(binary_data: bytes) -> MultiArrayLayout:
    py_obj = MultiArrayLayout()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_MultiArrayLayout(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_MultiArrayLayout(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: MultiArrayLayout, base_off: int):
    # array_type: varray 
    # data_type: struct 
    # member_name: dim 
    # type_name: MultiArrayDimension 
    # offset: 0 size: 136 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 0, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 0 + 4, 4))
    one_elm_size = 136
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = MultiArrayDimension()
        binary_read_recursive_MultiArrayDimension(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.dim = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: data_offset 
    # type_name: uint32 
    # offset: 8 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 4)
    py_obj.data_offset = binary_io.binTovalue("uint32", bin)
    
    return py_obj
