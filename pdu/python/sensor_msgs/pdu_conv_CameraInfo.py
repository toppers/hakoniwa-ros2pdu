
import struct
from .pdu_pytype_CameraInfo import CameraInfo
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..sensor_msgs.pdu_conv_RegionOfInterest import *



def pdu_to_py_CameraInfo(binary_data: bytes) -> CameraInfo:
    py_obj = CameraInfo()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_CameraInfo(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_CameraInfo(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: CameraInfo, base_off: int):
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
    # member_name: height 
    # type_name: uint32 
    # offset: 136 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 136, 4)
    py_obj.height = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 140 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 140, 4)
    py_obj.width = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: distortion_model 
    # type_name: string 
    # offset: 144 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 144, 128)
    py_obj.distortion_model = binary_io.binTovalue(type, bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: d 
    # type_name: float64 
    # offset: 272 size: 8 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 272, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 272 + 4, 4))
    one_elm_size = 8 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.d = array_value
    
    # array_type: array 
    # data_type: primitive 
    # member_name: k 
    # type_name: float64 
    # offset: 280 size: 72 
    # array_len: 9

    
    array_value = binary_io.readBinary(binary_data, base_off + 280, 72)
    py_obj.k = binary_io.binToArrayValues(type, array_value)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: r 
    # type_name: float64 
    # offset: 352 size: 72 
    # array_len: 9

    
    array_value = binary_io.readBinary(binary_data, base_off + 352, 72)
    py_obj.r = binary_io.binToArrayValues(type, array_value)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: p 
    # type_name: float64 
    # offset: 424 size: 96 
    # array_len: 12

    
    array_value = binary_io.readBinary(binary_data, base_off + 424, 96)
    py_obj.p = binary_io.binToArrayValues(type, array_value)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: binning_x 
    # type_name: uint32 
    # offset: 520 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 520, 4)
    py_obj.binning_x = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: binning_y 
    # type_name: uint32 
    # offset: 524 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 524, 4)
    py_obj.binning_y = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: struct 
    # member_name: roi 
    # type_name: RegionOfInterest 
    # offset: 528 size: 20 
    # array_len: 1

    tmp_py_obj = RegionOfInterest()
    binary_read_recursive_RegionOfInterest(meta, binary_data, tmp_py_obj, base_off + 528)
    py_obj.roi = tmp_py_obj
    
    return py_obj
