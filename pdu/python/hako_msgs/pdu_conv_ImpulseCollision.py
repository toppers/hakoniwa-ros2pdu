
import struct
from .pdu_pytype_ImpulseCollision import ImpulseCollision
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Point import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Point import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_ImpulseCollision(pdu_bytes: bytes) -> ImpulseCollision:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ImpulseCollision()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: collision (single)
    
    
    py_obj.collision = struct.unpack_from('<?', base_data, 0)[0]
    
    
    
    # Processing: is_target_static (single)
    
    
    py_obj.is_target_static = struct.unpack_from('<?', base_data, 4)[0]
    
    
    
    # Processing: restitution_coefficient (single)
    
    
    py_obj.restitution_coefficient = struct.unpack_from('<d', base_data, 8)[0]
    
    
    
    # Processing: self_contact_vector (single)
    
    
    nested_base_data = base_data[16:40]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.self_contact_vector = pdu_to_py_Point(nested_pdu_bytes)
    
    
    
    # Processing: normal (single)
    
    
    nested_base_data = base_data[40:64]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.normal = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: target_contact_vector (single)
    
    
    nested_base_data = base_data[64:88]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.target_contact_vector = pdu_to_py_Point(nested_pdu_bytes)
    
    
    
    # Processing: target_velocity (single)
    
    
    nested_base_data = base_data[88:112]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.target_velocity = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: target_angular_velocity (single)
    
    
    nested_base_data = base_data[112:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.target_angular_velocity = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: target_euler (single)
    
    
    nested_base_data = base_data[136:160]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.target_euler = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: target_inertia (single)
    
    
    nested_base_data = base_data[160:184]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.target_inertia = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: target_mass (single)
    
    
    py_obj.target_mass = struct.unpack_from('<d', base_data, 184)[0]
    
    
    
    return py_obj

def py_to_pdu_ImpulseCollision(py_obj: ImpulseCollision) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 192
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: collision (single)
    
    
    struct.pack_into('<?', base_buffer, 0, py_obj.collision)
    
    
    
    # Processing: is_target_static (single)
    
    
    struct.pack_into('<?', base_buffer, 4, py_obj.is_target_static)
    
    
    
    # Processing: restitution_coefficient (single)
    
    
    struct.pack_into('<d', base_buffer, 8, py_obj.restitution_coefficient)
    
    
    
    # Processing: self_contact_vector (single)
    
    
    nested_pdu_bytes = py_to_pdu_Point(py_obj.self_contact_vector)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[16:40] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: normal (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.normal)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[40:64] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_contact_vector (single)
    
    
    nested_pdu_bytes = py_to_pdu_Point(py_obj.target_contact_vector)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[64:88] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_velocity (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.target_velocity)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[88:112] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_angular_velocity (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.target_angular_velocity)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[112:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_euler (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.target_euler)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[136:160] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_inertia (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.target_inertia)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[160:184] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: target_mass (single)
    
    
    struct.pack_into('<d', base_buffer, 184, py_obj.target_mass)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
