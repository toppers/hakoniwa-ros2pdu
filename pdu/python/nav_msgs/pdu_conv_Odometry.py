
import struct
from .pdu_pytype_Odometry import Odometry
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_PoseWithCovariance import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_TwistWithCovariance import pdu_to_py_, py_to_pdu_


def pdu_to_py_Odometry(pdu_bytes: bytes) -> Odometry:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Odometry()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: child_frame_id (single)
    
    
    py_obj.child_frame_id = struct.unpack_from('<', base_data, 136)[0]
    
    
    
    # Processing: pose (single)
    
    
    nested_base_data = base_data[264:608]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.pose = pdu_to_py_PoseWithCovariance(nested_pdu_bytes)
    
    
    
    # Processing: twist (single)
    
    
    nested_base_data = base_data[608:944]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.twist = pdu_to_py_TwistWithCovariance(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_Odometry(py_obj: Odometry) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 944
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
    
    
    
    # Processing: pose (single)
    
    
    nested_pdu_bytes = py_to_pdu_PoseWithCovariance(py_obj.pose)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[264:608] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: twist (single)
    
    
    nested_pdu_bytes = py_to_pdu_TwistWithCovariance(py_obj.twist)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[608:944] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
