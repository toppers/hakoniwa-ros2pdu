
import struct
from .pdu_pytype_LaserScan import LaserScan
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *



def pdu_to_py_LaserScan(binary_data: bytes) -> LaserScan:
    py_obj = LaserScan()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_LaserScan(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_LaserScan(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: LaserScan, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: std_msgs/Header 
    # offset: 0 size: 136 
    # array_len: 1

    tmp_py_obj = Header()
    binary_read_recursive_Header(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: angle_min 
    # type_name: float32 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.angle_min = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: angle_max 
    # type_name: float32 
    # offset: 140 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 140, 4)
    py_obj.angle_max = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: angle_increment 
    # type_name: float32 
    # offset: 144 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 4)
    py_obj.angle_increment = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: time_increment 
    # type_name: float32 
    # offset: 148 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 148, 4)
    py_obj.time_increment = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: scan_time 
    # type_name: float32 
    # offset: 152 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 152, 4)
    py_obj.scan_time = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: range_min 
    # type_name: float32 
    # offset: 156 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 156, 4)
    py_obj.range_min = binary_io.binTovalue("float32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: range_max 
    # type_name: float32 
    # offset: 160 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 160, 4)
    py_obj.range_max = binary_io.binTovalue("float32", bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: ranges 
    # type_name: float32 
    # offset: 164 size: 4 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164 + 4, 4))
    one_elm_size = 4 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.ranges = array_value
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: intensities 
    # type_name: float32 
    # offset: 172 size: 4 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 172, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 172 + 4, 4))
    one_elm_size = 4 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.intensities = array_value
    
    return py_obj
