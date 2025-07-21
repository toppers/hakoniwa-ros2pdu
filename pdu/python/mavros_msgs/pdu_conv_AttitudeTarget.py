
import struct
from .pdu_pytype_AttitudeTarget import AttitudeTarget
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Quaternion import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_AttitudeTarget(pdu_bytes: bytes) -> AttitudeTarget:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = AttitudeTarget()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: type_mask (single)
    
    
    py_obj.type_mask = struct.unpack_from('<B', base_data, 136)[0]
    
    
    
    # Processing: orientation (single)
    
    
    nested_base_data = base_data[144:176]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.orientation = pdu_to_py_Quaternion(nested_pdu_bytes)
    
    
    
    # Processing: body_rate (single)
    
    
    nested_base_data = base_data[176:200]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.body_rate = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: thrust (single)
    
    
    py_obj.thrust = struct.unpack_from('<f', base_data, 200)[0]
    
    
    
    return py_obj

def py_to_pdu_AttitudeTarget(py_obj: AttitudeTarget) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 204
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: type_mask (single)
    
    
    struct.pack_into('<B', base_buffer, 136, py_obj.type_mask)
    
    
    
    # Processing: orientation (single)
    
    
    nested_pdu_bytes = py_to_pdu_Quaternion(py_obj.orientation)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[144:176] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: body_rate (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.body_rate)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[176:200] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: thrust (single)
    
    
    struct.pack_into('<f', base_buffer, 200, py_obj.thrust)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
