
import struct
from .pdu_pytype_Header import Header
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..builtin_interfaces.pdu_conv_Time import pdu_to_py_Time, py_to_pdu_Time


def pdu_to_py_Header(pdu_bytes: bytes) -> Header:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Header()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: stamp (single)
    
    
    nested_base_data = base_data[0:8]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.stamp = pdu_to_py_Time(nested_pdu_bytes)
    
    
    
    # Processing: frame_id (single)
    
    
        
    end = base_data.find(b'\0', 8)
    py_obj.frame_id = base_data[8:end].decode('utf-8')
        
    
    
    
    return py_obj

def py_to_pdu_Header(py_obj: Header) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 136
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: stamp (single)
    
    
    nested_pdu_bytes = py_to_pdu_Time(py_obj.stamp)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:8] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: frame_id (single)
    
    
    struct.pack_into('<', base_buffer, 8, py_obj.frame_id)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
