
import struct
from .pdu_pytype_HakoCmdCamera import HakoCmdCamera
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..hako_msgs.pdu_conv_HakoCmdHeader import *



def pdu_to_py_HakoCmdCamera(binary_data: bytearray) -> HakoCmdCamera:
    py_obj = HakoCmdCamera()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCmdCamera(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCmdCamera(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoCmdCamera, base_off: int):
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
    py_obj.request_id = binary_io.binTovalue("int32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encode_type 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 16, 4)
    py_obj.encode_type = binary_io.binTovalue("int32", bin)
    
    return py_obj



def py_to_pduHakoCmdCamera(py_obj: HakoCmdCamera) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoCmdCamera(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoCmdCamera(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoCmdCamera):
    # array_type: single 
    # data_type: struct 
    # member_name: header 
    # type_name: HakoCmdHeader 
    # offset: 0 size: 12 
    # array_len: 1
    type = "HakoCmdHeader"
    off = 0

    binary_write_recursive_HakoCmdHeader(parent_off + off, bw_container, allocator, py_obj.header)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: request_id 
    # type_name: int32 
    # offset: 12 size: 4 
    # array_len: 1
    type = "int32"
    off = 12

    
    bin = binary_io.typeTobin(type, py_obj.request_id)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: encode_type 
    # type_name: int32 
    # offset: 16 size: 4 
    # array_len: 1
    type = "int32"
    off = 16

    
    bin = binary_io.typeTobin(type, py_obj.encode_type)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
