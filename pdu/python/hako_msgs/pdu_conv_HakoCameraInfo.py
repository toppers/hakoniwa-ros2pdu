
import struct
from .pdu_pytype_HakoCameraInfo import HakoCameraInfo
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_HakoCameraInfo(pdu_bytes: bytes) -> HakoCameraInfo:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoCameraInfo()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: request_id (single)
    
    
    py_obj.request_id = struct.unpack_from('<i', base_data, 0)[0]
    
    
    
    # Processing: angle (single)
    
    
    nested_base_data = base_data[8:32]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.angle = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_HakoCameraInfo(py_obj: HakoCameraInfo) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 32
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: request_id (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.request_id)
    
    
    
    # Processing: angle (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.angle)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[8:32] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
