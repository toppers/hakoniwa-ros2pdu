
import struct
from .pdu_pytype_HakoCan import HakoCan
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..can_msgs.pdu_conv_HakoCanHead import pdu_to_py_, py_to_pdu_

from ..can_msgs.pdu_conv_HakoCanBody import pdu_to_py_, py_to_pdu_


def pdu_to_py_HakoCan(pdu_bytes: bytes) -> HakoCan:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoCan()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: head (single)
    
    
    nested_base_data = base_data[0:20]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.head = pdu_to_py_HakoCanHead(nested_pdu_bytes)
    
    
    
    # Processing: body (single)
    
    
    nested_base_data = base_data[20:28]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.body = pdu_to_py_HakoCanBody(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_HakoCan(py_obj: HakoCan) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 28
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: head (single)
    
    
    nested_pdu_bytes = py_to_pdu_HakoCanHead(py_obj.head)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:20] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: body (single)
    
    
    nested_pdu_bytes = py_to_pdu_HakoCanBody(py_obj.body)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[20:28] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
