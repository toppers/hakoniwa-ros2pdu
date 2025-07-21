
import struct
from .pdu_pytype_TFMessage import TFMessage
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_TransformStamped import *



def pdu_to_py_TFMessage(binary_data: bytes) -> TFMessage:
    py_obj = TFMessage()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_TFMessage(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_TFMessage(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: TFMessage, base_off: int):
    # array_type: varray 
    # data_type: struct 
    # member_name: transforms 
    # type_name: geometry_msgs/TransformStamped 
    # offset: 0 size: 320 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 0, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 0 + 4, 4))
    one_elm_size = 320
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = TransformStamped()
        binary_read_recursive_TransformStamped(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.transforms = array_value    
    
    return py_obj
