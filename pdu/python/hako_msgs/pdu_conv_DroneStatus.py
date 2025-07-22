
import struct
from .pdu_pytype_DroneStatus import DroneStatus
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..geometry_msgs.pdu_conv_Vector3 import *



def pdu_to_py_DroneStatus(binary_data: bytes) -> DroneStatus:
    py_obj = DroneStatus()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_DroneStatus(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_DroneStatus(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: DroneStatus, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: flight_mode 
    # type_name: int32 
    # offset: 0 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 4)
    py_obj.flight_mode = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: internal_state 
    # type_name: int32 
    # offset: 4 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 4, 4)
    py_obj.internal_state = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: propeller_wind 
    # type_name: geometry_msgs/Vector3 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = Vector3()
    binary_read_recursive_Vector3(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.propeller_wind = tmp_py_obj
    
    return py_obj
