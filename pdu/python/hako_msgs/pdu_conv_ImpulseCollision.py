
import struct
from .pdu_pytype_ImpulseCollision import ImpulseCollision
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Point import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_ImpulseCollision(binary_data: bytes) -> ImpulseCollision:
    py_obj = ImpulseCollision()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_ImpulseCollision(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_ImpulseCollision(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: ImpulseCollision, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: collision 
    # type_name: bool 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.collision = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_target_static 
    # type_name: bool 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.is_target_static = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: restitution_coefficient 
    # type_name: float64 
    # offset: 8 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 8, 8)
    py_obj.restitution_coefficient = binary_io.binTovalue("float64", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: self_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 16 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 16)
    py_obj.self_contact_vector = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: normal 
    # type_name: geometry_msgs/Vector3 
    # offset: 40 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 40)
    py_obj.normal = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_contact_vector 
    # type_name: geometry_msgs/Point 
    # offset: 64 size: 24 
    # array_len: 1

    tmp_py_obj = Point()
    binary_read_recursive_Point(meta, binary_data, tmp_py_obj, base_off + 64)
    py_obj.target_contact_vector = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 88 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 88)
    py_obj.target_velocity = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_angular_velocity 
    # type_name: geometry_msgs/Vector3 
    # offset: 112 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 112)
    py_obj.target_angular_velocity = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_euler 
    # type_name: geometry_msgs/Vector3 
    # offset: 136 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 136)
    py_obj.target_euler = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: target_inertia 
    # type_name: geometry_msgs/Vector3 
    # offset: 160 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 160)
    py_obj.target_inertia = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: target_mass 
    # type_name: float64 
    # offset: 184 size: 8 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 184, 8)
    py_obj.target_mass = binary_io.binTovalue("float64", bin)
    
    return py_obj
