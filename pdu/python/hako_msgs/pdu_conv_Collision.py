
import struct
from .pdu_pytype_Collision import Collision
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Point import *



def pdu_to_py_Collision(binary_data: bytes) -> Collision:
    py_obj = Collision()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Collision(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Collision(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Collision, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: collision 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.collision = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: contact_num 
    # type_name: uint32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.contact_num = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: relative_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.relative_velocity = tmp_py_obj
    
    # array_type: array 
    # data_type: struct 
    # member_name: contact_position 
    # type_name: geometry_msgs/Point 
    # offset: 32 size: 240 
    # array_len: 10

    i = 0
    array_size = 10
    one_elm_size = int(240) / array_size
    array_value = []
    while i < array_size:
        tmp_py_obj = Point()
        binary_read_recursive_Point(meta, binary_data, tmp_py_obj, 32 + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.contact_position = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 272 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 272, 8)
    py_obj.restitution_coefficient = binary_io.binTovalue(type, bin)
    
    return py_obj
