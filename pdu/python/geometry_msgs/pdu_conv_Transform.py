
import struct
from .pdu_pytype_Transform import Transform
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Quaternion import *



def pdu_to_py_Transform(binary_data: bytes) -> Transform:
    py_obj = Transform()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Transform(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Transform(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Transform, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: translation 
    # type_name: Vector3 
    # offset: 0 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.translation = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: rotation 
    # type_name: Quaternion 
    # offset: 24 size: 32 
    # array_len: 1

    tmp_py_obj = Quaternion()
    binary_read_recursive_Quaternion(meta, binary_data, tmp_py_obj, base_off + 24)
    py_obj.rotation = tmp_py_obj
    
    return py_obj
