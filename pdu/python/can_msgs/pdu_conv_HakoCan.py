
import struct
from .pdu_pytype_HakoCan import HakoCan
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class
from ..can_msgs.pdu_conv_HakoCanHead import *
from ..can_msgs.pdu_conv_HakoCanBody import *



def pdu_to_py_HakoCan(binary_data: bytearray) -> HakoCan:
    py_obj = HakoCan()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_HakoCan(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_HakoCan(meta: binary_io.PduMetaData, binary_data: bytearray, py_obj: HakoCan, base_off: int):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: HakoCanHead 
    # offset: 0 size: 20 
    # array_len: 1

    tmp_py_obj = HakoCanHead()
    binary_read_recursive_HakoCanHead(meta, binary_data, tmp_py_obj, base_off + 0)
    py_obj.head = tmp_py_obj
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: HakoCanBody 
    # offset: 20 size: 8 
    # array_len: 1

    tmp_py_obj = HakoCanBody()
    binary_read_recursive_HakoCanBody(meta, binary_data, tmp_py_obj, base_off + 20)
    py_obj.body = tmp_py_obj
    
    return py_obj



def py_to_pduHakoCan(py_obj: HakoCan) -> bytearray:
    binary_data = bytearray()
    base_allocator = DynamicAllocator(False)
    bw_container = BinaryWriterContainer(binary_io.PduMetaData())
    binary_write_recursive_HakoCan(0, bw_container, base_allocator, py_obj)

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

def binary_write_recursive_HakoCan(parent_off: int, bw_container: BinaryWriterContainer, allocator, py_obj: HakoCan):
    # array_type: single 
    # data_type: struct 
    # member_name: head 
    # type_name: HakoCanHead 
    # offset: 0 size: 20 
    # array_len: 1
    type = "HakoCanHead"
    off = 0

    binary_write_recursive_HakoCanHead(parent_off + off, bw_container, allocator, py_obj.head)
    
    # array_type: single 
    # data_type: struct 
    # member_name: body 
    # type_name: HakoCanBody 
    # offset: 20 size: 8 
    # array_len: 1
    type = "HakoCanBody"
    off = 20

    binary_write_recursive_HakoCanBody(parent_off + off, bw_container, allocator, py_obj.body)
    
