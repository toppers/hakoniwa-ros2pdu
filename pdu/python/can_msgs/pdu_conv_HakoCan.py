
import struct
from .pdu_pytype_HakoCan import HakoCan
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..can_msgs.pdu_conv_HakoCanHead import *
from ..can_msgs.pdu_conv_HakoCanBody import *



def pdu_to_py_HakoCan(binary_data: bytes) -> HakoCan:
    py_obj = HakoCan()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCan(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCan(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: HakoCan, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: HakoCanHead 
    # offset: 0 size: 20 
    # array_len: 1

    tmp_py_obj = HakoCanHead()
    binary_read_recursive_HakoCanHead(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.head = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: HakoCanBody 
    # offset: 20 size: 8 
    # array_len: 1

    tmp_py_obj = HakoCanBody()
    binary_read_recursive_HakoCanBody(meta, binary_data, tmp_py_obj, base_off + 20)
    py_obj.body = tmp_py_obj
    
    return py_obj
