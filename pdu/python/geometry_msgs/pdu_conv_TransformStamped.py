
import struct
from .pdu_pytype_TransformStamped import TransformStamped
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_Header, py_to_pdu_Header

from ..geometry_msgs.pdu_conv_Transform import pdu_to_py_Transform, py_to_pdu_Transform


def pdu_to_py_TransformStamped(pdu_bytes: bytes) -> TransformStamped:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = TransformStamped()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: child_frame_id (single)
    
    
        
    end = base_data.find(b'\0', 136)
    py_obj.child_frame_id = base_data[136:end].decode('utf-8')
        
    
    
    
    # Processing: transform (single)
    
    
    nested_base_data = base_data[264:320]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.transform = pdu_to_py_Transform(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_TransformStamped(py_obj: TransformStamped) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 320
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: child_frame_id (single)
    
    
    struct.pack_into('<', base_buffer, 136, py_obj.child_frame_id)
    
    
    
    # Processing: transform (single)
    
    
    nested_pdu_bytes = py_to_pdu_Transform(py_obj.transform)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[264:320] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
