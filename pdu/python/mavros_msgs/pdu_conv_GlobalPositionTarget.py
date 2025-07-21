
import struct
from .pdu_pytype_GlobalPositionTarget import GlobalPositionTarget
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_GlobalPositionTarget(pdu_bytes: bytes) -> GlobalPositionTarget:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = GlobalPositionTarget()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: coordinate_frame (single)
    
    
    py_obj.coordinate_frame = struct.unpack_from('<B', base_data, 136)[0]
    
    
    
    # Processing: type_mask (single)
    
    
    py_obj.type_mask = struct.unpack_from('<H', base_data, 138)[0]
    
    
    
    # Processing: latitude (single)
    
    
    py_obj.latitude = struct.unpack_from('<d', base_data, 144)[0]
    
    
    
    # Processing: longitude (single)
    
    
    py_obj.longitude = struct.unpack_from('<d', base_data, 152)[0]
    
    
    
    # Processing: altitude (single)
    
    
    py_obj.altitude = struct.unpack_from('<f', base_data, 160)[0]
    
    
    
    # Processing: velocity (single)
    
    
    nested_base_data = base_data[168:192]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.velocity = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: acceleration_or_force (single)
    
    
    nested_base_data = base_data[192:216]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.acceleration_or_force = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: yaw (single)
    
    
    py_obj.yaw = struct.unpack_from('<f', base_data, 216)[0]
    
    
    
    # Processing: yaw_rate (single)
    
    
    py_obj.yaw_rate = struct.unpack_from('<f', base_data, 220)[0]
    
    
    
    return py_obj

def py_to_pdu_GlobalPositionTarget(py_obj: GlobalPositionTarget) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 224
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: coordinate_frame (single)
    
    
    struct.pack_into('<B', base_buffer, 136, py_obj.coordinate_frame)
    
    
    
    # Processing: type_mask (single)
    
    
    struct.pack_into('<H', base_buffer, 138, py_obj.type_mask)
    
    
    
    # Processing: latitude (single)
    
    
    struct.pack_into('<d', base_buffer, 144, py_obj.latitude)
    
    
    
    # Processing: longitude (single)
    
    
    struct.pack_into('<d', base_buffer, 152, py_obj.longitude)
    
    
    
    # Processing: altitude (single)
    
    
    struct.pack_into('<f', base_buffer, 160, py_obj.altitude)
    
    
    
    # Processing: velocity (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.velocity)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[168:192] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: acceleration_or_force (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.acceleration_or_force)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[192:216] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: yaw (single)
    
    
    struct.pack_into('<f', base_buffer, 216, py_obj.yaw)
    
    
    
    # Processing: yaw_rate (single)
    
    
    struct.pack_into('<f', base_buffer, 220, py_obj.yaw_rate)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
