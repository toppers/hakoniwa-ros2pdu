
import struct
from .pdu_pytype_SimpleStructVarray import SimpleStructVarray
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_SimpleVarray import *
from ..hako_msgs.pdu_conv_SimpleVarray import *



def pdu_to_py_SimpleStructVarray(binary_data: bytes) -> SimpleStructVarray:
    py_obj = SimpleStructVarray()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_SimpleStructVarray(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_SimpleStructVarray(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: SimpleStructVarray, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: aaa 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.aaa = binary_io.binTovalue(type, bin)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: fixed_str 
    # type_name: string 
    # offset: 4 size: 256 
    # array_len: 2

    
    array_value = binary_io.readBinary(binary_data, base_off + 4, 256)
    py_obj.fixed_str = binary_io.binToArrayValues(type, array_value)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: varray_str 
    # type_name: string 
    # offset: 260 size: 128 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 260, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 260 + 4, 4))
    one_elm_size = 128 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.varray_str = array_value
    
    # array_type: array 
    # data_type: struct 
    # member_name: fixed_array 
    # type_name: SimpleVarray 
    # offset: 268 size: 120 
    # array_len: 5

    i = 0
    array_size = 5
    one_elm_size = int(120) / array_size
    array_value = []
    while i < array_size:
        tmp_py_obj = SimpleVarray()
        binary_read_recursive_SimpleVarray(meta, binary_data, tmp_py_obj, 268 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.fixed_array = array_value    
    
    # array_type: varray 
    # data_type: struct 
    # member_name: data 
    # type_name: SimpleVarray 
    # offset: 388 size: 24 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 388, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 388 + 4, 4))
    one_elm_size = 24
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = SimpleVarray()
        binary_read_recursive_SimpleVarray(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.data = array_value    
    
    return py_obj
