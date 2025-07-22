
import struct
from .pdu_pytype_SimpleVarray import SimpleVarray
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_SimpleVarray(binary_data: bytes) -> SimpleVarray:
    py_obj = SimpleVarray()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_SimpleVarray(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_SimpleVarray(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: SimpleVarray, base_off: int):
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: int8 
    # offset: 0 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 0 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_array 
    # type_name: int8 
    # offset: 8 size: 10 
    # array_len: 10

    
    array_value = binary_io.readBinary(binary_data, base_off + 8, 10)
    py_obj.fixed_array = binary_io.binToArrayValues("int8", array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: p_mem1 
    # type_name: int32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.p_mem1 = binary_io.binTovalue("int32", bin)
    
    return py_obj
