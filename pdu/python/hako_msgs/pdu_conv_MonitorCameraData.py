
import struct
from .pdu_pytype_MonitorCameraData import MonitorCameraData
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..sensor_msgs.pdu_conv_CompressedImage import pdu_to_py_, py_to_pdu_


def pdu_to_py_MonitorCameraData(pdu_bytes: bytes) -> MonitorCameraData:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = MonitorCameraData()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: request_id (single)
    
    
    py_obj.request_id = struct.unpack_from('<i', base_data, 0)[0]
    
    
    
    # Processing: image_data_length (single)
    
    
    py_obj.image_data_length = struct.unpack_from('<i', base_data, 4)[0]
    
    
    
    # Processing: image (single)
    
    
    nested_base_data = base_data[8:280]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.image = pdu_to_py_CompressedImage(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_MonitorCameraData(py_obj: MonitorCameraData) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 280
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: request_id (single)
    
    
    struct.pack_into('<i', base_buffer, 0, py_obj.request_id)
    
    
    
    # Processing: image_data_length (single)
    
    
    struct.pack_into('<i', base_buffer, 4, py_obj.image_data_length)
    
    
    
    # Processing: image (single)
    
    
    nested_pdu_bytes = py_to_pdu_CompressedImage(py_obj.image)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[8:280] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
