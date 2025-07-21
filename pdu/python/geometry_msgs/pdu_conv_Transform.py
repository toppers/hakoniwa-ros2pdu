
import struct
from .pdu_pytype_Transform import Transform
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_Vector3, py_to_pdu_Vector3

from ..geometry_msgs.pdu_conv_Quaternion import pdu_to_py_Quaternion, py_to_pdu_Quaternion


def pdu_to_py_Transform(pdu_bytes: bytes) -> Transform:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Transform()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: translation (single)
    
    
    nested_base_data = base_data[0:24]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.translation = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: rotation (single)
    
    
    nested_base_data = base_data[24:56]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.rotation = pdu_to_py_Quaternion(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_Transform(py_obj: Transform) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 56
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: translation (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.translation)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:24] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: rotation (single)
    
    
    nested_pdu_bytes = py_to_pdu_Quaternion(py_obj.rotation)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[24:56] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
