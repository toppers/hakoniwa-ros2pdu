
import struct
from .pdu_pytype_ShareObjectOwner import ShareObjectOwner
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Twist import pdu_to_py_, py_to_pdu_


def pdu_to_py_ShareObjectOwner(pdu_bytes: bytes) -> ShareObjectOwner:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ShareObjectOwner()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: object_name (single)
    
    
    py_obj.object_name = struct.unpack_from('<', base_data, 0)[0]
    
    
    
    # Processing: owner_id (single)
    
    
    py_obj.owner_id = struct.unpack_from('<I', base_data, 128)[0]
    
    
    
    # Processing: last_update (single)
    
    
    py_obj.last_update = struct.unpack_from('<Q', base_data, 136)[0]
    
    
    
    # Processing: pos (single)
    
    
    nested_base_data = base_data[144:192]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.pos = pdu_to_py_Twist(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_ShareObjectOwner(py_obj: ShareObjectOwner) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 192
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: object_name (single)
    
    
    struct.pack_into('<', base_buffer, 0, py_obj.object_name)
    
    
    
    # Processing: owner_id (single)
    
    
    struct.pack_into('<I', base_buffer, 128, py_obj.owner_id)
    
    
    
    # Processing: last_update (single)
    
    
    struct.pack_into('<Q', base_buffer, 136, py_obj.last_update)
    
    
    
    # Processing: pos (single)
    
    
    nested_pdu_bytes = py_to_pdu_Twist(py_obj.pos)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[144:192] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
