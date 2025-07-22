
import struct
from .pdu_pytype_AddTwoIntsResponsePacket import AddTwoIntsResponsePacket
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_srv_msgs.pdu_conv_ServiceResponseHeader import *
from ..hako_srv_msgs.pdu_conv_AddTwoIntsResponse import *



def pdu_to_py_AddTwoIntsResponsePacket(binary_data: bytearray) -> AddTwoIntsResponsePacket:
    py_obj = AddTwoIntsResponsePacket()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_AddTwoIntsResponsePacket(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_AddTwoIntsResponsePacket(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: AddTwoIntsResponsePacket, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: ServiceResponseHeader 
    # offset: 0 size: 268 
    # array_len: 1

    tmp_py_obj = ServiceResponseHeader()
    binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.header = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: AddTwoIntsResponse 
    # offset: 272 size: 8 
    # array_len: 1

    tmp_py_obj = AddTwoIntsResponse()
    binary_read_recursive_AddTwoIntsResponse(meta, binary_data, tmp_py_obj, base_off + 272)
    py_obj.body = tmp_py_obj
    
    return py_obj



def py_to_pduAddTwoIntsResponsePacket(py_obj: AddTwoIntsResponsePacket) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_AddTwoIntsResponsePacket(0, bw_container, base_allocator, py_obj)

    # メタデータの設定
    total_size = base_allocator.size() + bw_container.heap_allocator.size() + binary_io.PduMetaData.PDU_META_DATA_SIZE
    bw_container.meta.total_size = total_size
    bw_container.meta.heap_off = binary_io.PduMetaData.PDU_META_DATA_SIZE + base_allocator.size()

    # binary_data のサイズを total_size に調整
    if len(binary_data) < total_size:
        binary_data.extend(bytearray(total_size - len(binary_data)))
    elif len(binary_data) > total_size:
        del binary_data[total_size:]

    # メタデータをバッファにコピー
    binary_io.writeBinary(binary_data, 0, bw_container.meta.to_bytes())

    # 基本データをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.base_off, base_allocator.to_array())

    # ヒープデータをバッファにコピー
    binary_io.writeBinary(binary_data, bw_container.meta.heap_off, bw_container.heap_allocator.to_array())

    return binary_data

def binary_write_recursive_AddTwoIntsResponsePacket(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: AddTwoIntsResponsePacket):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: ServiceResponseHeader 
    # offset: 0 size: 268 
    # array_len: 1
    type = "ServiceResponseHeader"
    off = 0

    binary_write_recursive_ServiceResponseHeader(parent_off + off, bw_container, allocator, py_obj.header)
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: AddTwoIntsResponse 
    # offset: 272 size: 8 
    # array_len: 1
    type = "AddTwoIntsResponse"
    off = 272

    binary_write_recursive_AddTwoIntsResponse(parent_off + off, bw_container, allocator, py_obj.body)
    
