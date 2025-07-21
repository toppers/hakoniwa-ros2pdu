
import struct
from .pdu_pytype_DisturbanceBoundary import DisturbanceBoundary
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Point import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_DisturbanceBoundary(pdu_bytes: bytes) -> DisturbanceBoundary:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = DisturbanceBoundary()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: boundary_point (single)
    
    
    nested_base_data = base_data[0:24]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.boundary_point = pdu_to_py_Point(nested_pdu_bytes)
    
    
    
    # Processing: boundary_normal (single)
    
    
    nested_base_data = base_data[24:48]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.boundary_normal = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_DisturbanceBoundary(py_obj: DisturbanceBoundary) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 48
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: boundary_point (single)
    
    
    nested_pdu_bytes = py_to_pdu_Point(py_obj.boundary_point)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:24] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: boundary_normal (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.boundary_normal)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[24:48] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
