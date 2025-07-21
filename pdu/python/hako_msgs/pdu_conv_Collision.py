
import struct
from .pdu_pytype_Collision import Collision
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Point import pdu_to_py_, py_to_pdu_


def pdu_to_py_Collision(pdu_bytes: bytes) -> Collision:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Collision()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: collision (single)
    
    
    py_obj.collision = struct.unpack_from('<?', base_data, 0)[0]
    
    
    
    # Processing: contact_num (single)
    
    
    py_obj.contact_num = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: relative_velocity (single)
    
    
    nested_base_data = base_data[8:32]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.relative_velocity = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    # Processing: contact_position (array)
    
    py_obj.contact_position = []
    element_size = 24
    for i in range(10):
        element_offset = 32 + i * element_size
    
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_Point(nested_pdu_bytes)
        py_obj.contact_position.append(val)
    
    
    
    # Processing: restitution_coefficient (single)
    
    
    py_obj.restitution_coefficient = struct.unpack_from('<d', base_data, 272)[0]
    
    
    
    return py_obj

def py_to_pdu_Collision(py_obj: Collision) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 280
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: collision (single)
    
    
    struct.pack_into('<?', base_buffer, 0, py_obj.collision)
    
    
    
    # Processing: contact_num (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.contact_num)
    
    
    
    # Processing: relative_velocity (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.relative_velocity)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[8:32] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: contact_position (array)
    
    element_size = 24
    for i, element in enumerate(py_obj.contact_position):
        if i >= 10: break
        element_offset = 32 + i * element_size
    
        nested_pdu_bytes = py_to_pdu_Point(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    
    
    
    # Processing: restitution_coefficient (single)
    
    
    struct.pack_into('<d', base_buffer, 272, py_obj.restitution_coefficient)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
