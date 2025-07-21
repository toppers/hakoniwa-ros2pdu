
import struct
from .pdu_pytype_MonitorCameraCmd import MonitorCameraCmd
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_HakoCmdHeader import *



def pdu_to_py_MonitorCameraCmd(binary_data: bytes) -> MonitorCameraCmd:
    py_obj = MonitorCameraCmd()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_MonitorCameraCmd(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_MonitorCameraCmd(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: MonitorCameraCmd, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: HakoCmdHeader 
    # offset: 0 size: 12 
    # array_len: 1

    tmp_py_obj = HakoCmdHeader()
    binary_read_recursive_HakoCmdHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 12, 4)
    py_obj.request_id = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encode_type 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.encode_type = binary_io.binTovalue(type, bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: request_type 
    # type_name: int32 
    # offset: 20 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 20, 4)
    py_obj.request_type = binary_io.binTovalue(type, bin)
    
    return py_obj
