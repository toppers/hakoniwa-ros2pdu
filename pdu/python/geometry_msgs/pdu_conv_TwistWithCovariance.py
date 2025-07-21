
import struct
from .pdu_pytype_TwistWithCovariance import TwistWithCovariance
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Twist import pdu_to_py_, py_to_pdu_


def pdu_to_py_TwistWithCovariance(pdu_bytes: bytes) -> TwistWithCovariance:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = TwistWithCovariance()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: twist (single)
    
    
    nested_base_data = base_data[0:48]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.twist = pdu_to_py_Twist(nested_pdu_bytes)
    
    
    
    # Processing: covariance (array)
    
    py_obj.covariance = []
    element_size = 8
    for i in range(36):
        element_offset = 48 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.covariance.append(val)
    
    
    
    return py_obj

def py_to_pdu_TwistWithCovariance(py_obj: TwistWithCovariance) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 336
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: twist (single)
    
    
    nested_pdu_bytes = py_to_pdu_Twist(py_obj.twist)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:48] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: covariance (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.covariance):
        if i >= 36: break
        element_offset = 48 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
