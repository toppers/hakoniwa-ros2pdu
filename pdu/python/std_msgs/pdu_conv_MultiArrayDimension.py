
import struct
from .pdu_pytype_MultiArrayDimension import MultiArrayDimension
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_MultiArrayDimension(binary_data: bytearray) -> MultiArrayDimension:
    py_obj = MultiArrayDimension()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_MultiArrayDimension(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_MultiArrayDimension(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: MultiArrayDimension, base_off: int):
    # array_type: single 
    # data_type: primitive 
    # member_name: label 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 0, 128)
    py_obj.label = binary_io.binTovalue("string", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: size 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 128, 4)
    py_obj.size = binary_io.binTovalue("uint32", bin)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: stride 
    # type_name: uint32 
    # offset: 132 size: 4 
    # array_len: 1

    
    bin = binary_io.readBinary(binary_data, base_off + 132, 4)
    py_obj.stride = binary_io.binTovalue("uint32", bin)
    
    return py_obj



def py_to_pdu_MultiArrayDimension(py_obj: MultiArrayDimension) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_MultiArrayDimension(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_MultiArrayDimension(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: MultiArrayDimension):
    # array_type: single 
    # data_type: primitive 
    # member_name: label 
    # type_name: string 
    # offset: 0 size: 128 
    # array_len: 1
    type = "string"
    off = 0

    
    bin = binary_io.typeTobin(type, py_obj.label)
    bin = get_binary(type, bin, 128)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: size 
    # type_name: uint32 
    # offset: 128 size: 4 
    # array_len: 1
    type = "uint32"
    off = 128

    
    bin = binary_io.typeTobin(type, py_obj.size)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
    # array_type: single 
    # data_type: primitive 
    # member_name: stride 
    # type_name: uint32 
    # offset: 132 size: 4 
    # array_len: 1
    type = "uint32"
    off = 132

    
    bin = binary_io.typeTobin(type, py_obj.stride)
    bin = get_binary(type, bin, 4)
    allocator.add(bin, expected_offset=parent_off + off)
    
