
import struct
from .pdu_pytype_HakoCmdCameraMove import HakoCmdCameraMove
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..hako_msgs.pdu_conv_HakoCmdHeader import pdu_to_py_, py_to_pdu_

from ..geometry_msgs.pdu_conv_Vector3 import pdu_to_py_, py_to_pdu_


def pdu_to_py_HakoCmdCameraMove(pdu_bytes: bytes) -> HakoCmdCameraMove:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoCmdCameraMove()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:12]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_HakoCmdHeader(nested_pdu_bytes)
    
    
    
    # Processing: request_id (single)
    
    
    py_obj.request_id = struct.unpack_from('<i', base_data, 12)[0]
    
    
    
    # Processing: angle (single)
    
    
    nested_base_data = base_data[16:40]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.angle = pdu_to_py_Vector3(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_HakoCmdCameraMove(py_obj: HakoCmdCameraMove) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 40
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_HakoCmdHeader(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:12] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: request_id (single)
    
    
    struct.pack_into('<i', base_buffer, 12, py_obj.request_id)
    
    
    
    # Processing: angle (single)
    
    
    nested_pdu_bytes = py_to_pdu_Vector3(py_obj.angle)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[16:40] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
