
import struct
from .pdu_pytype_Disturbance import Disturbance
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_DisturbanceTemperature import *
from ..hako_msgs.pdu_conv_DisturbanceWind import *
from ..hako_msgs.pdu_conv_DisturbanceAtm import *
from ..hako_msgs.pdu_conv_DisturbanceBoundary import *



def pdu_to_py_Disturbance(binary_data: bytes) -> Disturbance:
    py_obj = Disturbance()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_Disturbance(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_Disturbance(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: Disturbance, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: d_temp 
    # type_name: hako_msgs/DisturbanceTemperature 
    # offset: 0 size: 8 
    # array_len: 1

    tmp_py_obj = DisturbanceTemperature()
    binary_read_recursive_DisturbanceTemperature(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.d_temp = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_wind 
    # type_name: hako_msgs/DisturbanceWind 
    # offset: 8 size: 24 
    # array_len: 1

    tmp_py_obj = DisturbanceWind()
    binary_read_recursive_DisturbanceWind(meta, binary_data, tmp_py_obj, base_off + 8)
    py_obj.d_wind = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_atm 
    # type_name: hako_msgs/DisturbanceAtm 
    # offset: 32 size: 8 
    # array_len: 1

    tmp_py_obj = DisturbanceAtm()
    binary_read_recursive_DisturbanceAtm(meta, binary_data, tmp_py_obj, base_off + 32)
    py_obj.d_atm = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: d_boundary 
    # type_name: hako_msgs/DisturbanceBoundary 
    # offset: 40 size: 48 
    # array_len: 1

    tmp_py_obj = DisturbanceBoundary()
    binary_read_recursive_DisturbanceBoundary(meta, binary_data, tmp_py_obj, base_off + 40)
    py_obj.d_boundary = tmp_py_obj
    
    return py_obj
