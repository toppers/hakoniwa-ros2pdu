
import struct
from .pdu_pytype_Imu import Imu
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Quaternion import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_Imu(pdu_bytes: bytes) -> Imu:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Imu()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: orientation (single)
    
    
    nested_base_data = base_data[136:168]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.orientation = pdu_to_py_Quaternion(nested_pdu_bytes)
    
    
    
    # Processing: orientation_covariance (array)
    
    py_obj.orientation_covariance = []
    element_size = 8
    for i in range(9):
        element_offset = 168 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.orientation_covariance.append(val)
    
    
    
    # Processing: angular_velocity (single)
    
    
    nested_base_data = base_data[240:264]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.angular_velocity = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: angular_velocity_covariance (array)
    
    py_obj.angular_velocity_covariance = []
    element_size = 8
    for i in range(9):
        element_offset = 264 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.angular_velocity_covariance.append(val)
    
    
    
    # Processing: linear_acceleration (single)
    
    
    nested_base_data = base_data[336:360]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.linear_acceleration = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: linear_acceleration_covariance (array)
    
    py_obj.linear_acceleration_covariance = []
    element_size = 8
    for i in range(9):
        element_offset = 360 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.linear_acceleration_covariance.append(val)
    
    
    
    return py_obj

def py_to_pdu_Imu(py_obj: Imu) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 432
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: orientation (single)
    
    
    nested_pdu_bytes = py_to_pdu_Quaternion(py_obj.orientation)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[136:168] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: orientation_covariance (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.orientation_covariance):
        if i >= 9: break
        element_offset = 168 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: angular_velocity (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.angular_velocity)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[240:264] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: angular_velocity_covariance (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.angular_velocity_covariance):
        if i >= 9: break
        element_offset = 264 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: linear_acceleration (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.linear_acceleration)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[336:360] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: linear_acceleration_covariance (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.linear_acceleration_covariance):
        if i >= 9: break
        element_offset = 360 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
