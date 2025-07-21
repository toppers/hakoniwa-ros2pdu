
import struct
from .pdu_pytype_AddTwoIntsResponsePacket import AddTwoIntsResponsePacket
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..hako_srv_msgs.pdu_conv_ServiceResponseHeader import pdu_to_py_, py_to_pdu_

from ..hako_srv_msgs.pdu_conv_AddTwoIntsResponse import pdu_to_py_, py_to_pdu_


def pdu_to_py_AddTwoIntsResponsePacket(pdu_bytes: bytes) -> AddTwoIntsResponsePacket:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = AddTwoIntsResponsePacket()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:268]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_ServiceResponseHeader(nested_pdu_bytes)
    
    
    
    # Processing: body (single)
    
    
    nested_base_data = base_data[272:280]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.body = pdu_to_py_AddTwoIntsResponse(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_AddTwoIntsResponsePacket(py_obj: AddTwoIntsResponsePacket) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 280
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_ServiceResponseHeader(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:268] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: body (single)
    
    
    nested_pdu_bytes = py_to_pdu_AddTwoIntsResponse(py_obj.body)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[272:280] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
