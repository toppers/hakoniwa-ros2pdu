
import struct
from .pdu_pytype_HakoDroneCmdMove import HakoDroneCmdMove
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..hako_msgs.pdu_conv_HakoDroneCmdHeader import pdu_to_py_, py_to_pdu_


def pdu_to_py_HakoDroneCmdMove(pdu_bytes: bytes) -> HakoDroneCmdMove:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoDroneCmdMove()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:12]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_HakoDroneCmdHeader(nested_pdu_bytes)
    
    
    
    # Processing: x (single)
    
    
    py_obj.x = struct.unpack_from('<d', base_data, 16)[0]
    
    
    
    # Processing: y (single)
    
    
    py_obj.y = struct.unpack_from('<d', base_data, 24)[0]
    
    
    
    # Processing: z (single)
    
    
    py_obj.z = struct.unpack_from('<d', base_data, 32)[0]
    
    
    
    # Processing: speed (single)
    
    
    py_obj.speed = struct.unpack_from('<d', base_data, 40)[0]
    
    
    
    # Processing: yaw_deg (single)
    
    
    py_obj.yaw_deg = struct.unpack_from('<d', base_data, 48)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoDroneCmdMove(py_obj: HakoDroneCmdMove) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 56
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_HakoDroneCmdHeader(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:12] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: x (single)
    
    
    struct.pack_into('<d', base_buffer, 16, py_obj.x)
    
    
    
    # Processing: y (single)
    
    
    struct.pack_into('<d', base_buffer, 24, py_obj.y)
    
    
    
    # Processing: z (single)
    
    
    struct.pack_into('<d', base_buffer, 32, py_obj.z)
    
    
    
    # Processing: speed (single)
    
    
    struct.pack_into('<d', base_buffer, 40, py_obj.speed)
    
    
    
    # Processing: yaw_deg (single)
    
    
    struct.pack_into('<d', base_buffer, 48, py_obj.yaw_deg)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
