
import struct
from .pdu_pytype_PointCloud2 import PointCloud2
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..std_msgs.pdu_conv_Header import *
from ..sensor_msgs.pdu_conv_PointField import *



def pdu_to_py_PointCloud2(binary_data: bytes) -> PointCloud2:
    py_obj = PointCloud2()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_PointCloud2(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_PointCloud2(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: PointCloud2, base_off: int):
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
    py_obj.height = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: width 
    # type_name: uint32 
    # offset: 140 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 140, 4)
    py_obj.width = binary_io.binTovalue("uint32", bin)
    
    # array_type: varray 
    # data_type: struct 
    # member_name: fields 
    # type_name: PointField 
    # offset: 144 size: 140 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 144, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, 144 + 4, 4))
    one_elm_size = 140
    i = 0
    array_value = []
    while i < array_size:
        tmp_py_obj = PointField()
        binary_read_recursive_PointField(meta, binary_data, tmp_py_obj, meta.heap_off + offset_from_heap + (i * one_elm_size))
        array_value.append(tmp_py_obj)
        i = i + 1
    py_obj.fields = array_value    
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_bigendian 
    # type_name: bool 
    # offset: 152 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 152, 4)
    py_obj.is_bigendian = binary_io.binTovalue("bool", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: point_step 
    # type_name: uint32 
    # offset: 156 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 156, 4)
    py_obj.point_step = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: row_step 
    # type_name: uint32 
    # offset: 160 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 160, 4)
    py_obj.row_step = binary_io.binTovalue("uint32", bin)
    
    # array_type: varray 
    # data_type: primitive 
    # member_name: data 
    # type_name: uint8 
    # offset: 164 size: 1 
    # array_len: 8

    array_size = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164, 4))
    offset_from_heap = binary_io.binTovalue("int32", binary_io.readBinary(binary_data, base_off + 164 + 4, 4))
    one_elm_size = 1 
    array_value = binary_io.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size)
    py_obj.data = array_value
    
    # array_type: single 
    # data_type: primitive 
    # member_name: is_dense 
    # type_name: bool 
    # offset: 172 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 172, 4)
    py_obj.is_dense = binary_io.binTovalue("bool", bin)
    
    return py_obj
