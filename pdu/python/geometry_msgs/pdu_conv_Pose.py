
import struct
from .pdu_pytype_Pose import Pose
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Point import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Quaternion import pdu_to_py_, py_to_pdu_


def pdu_to_py_Pose(pdu_bytes: bytes) -> Pose:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Pose()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: position (single)
    
    
    nested_base_data = base_data[0:24]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.position = pdu_to_py_Point(nested_pdu_bytes)
    
    
    
    # Processing: orientation (single)
    
    
    nested_base_data = base_data[24:56]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.orientation = pdu_to_py_Quaternion(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_Pose(py_obj: Pose) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 56
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: position (single)
    
    
    nested_pdu_bytes = py_to_pdu_Point(py_obj.position)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:24] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: orientation (single)
    
    
    nested_pdu_bytes = py_to_pdu_Quaternion(py_obj.orientation)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[24:56] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
