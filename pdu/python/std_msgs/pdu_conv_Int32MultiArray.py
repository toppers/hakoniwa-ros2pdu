
import struct
from .pdu_pytype_Int32MultiArray import Int32MultiArray
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_MultiArrayLayout import *



def pdu_to_py_Int32MultiArray(binary_data: bytes) -> Int32MultiArray:
    py_obj = Int32MultiArray()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Int32MultiArray(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Int32MultiArray(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Int32MultiArray, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: layout 
    # type_name: MultiArrayLayout 
    # offset: 0 size: 12 
    # array_len: 1

    tmp_py_obj = MultiArrayLayout()
    binary_read_recursive_MultiArrayLayout(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.layout = tmp_py_obj
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 12, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 12 + 4, 4))
    one_elm_size = 4 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    return py_obj
