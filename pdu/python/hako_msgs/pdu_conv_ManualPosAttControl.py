
import struct
from .pdu_pytype_ManualPosAttControl import ManualPosAttControl
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_Twist import pdu_to_py_, py_to_pdu_


def pdu_to_py_ManualPosAttControl(pdu_bytes: bytes) -> ManualPosAttControl:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ManualPosAttControl()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: do_operation (single)
    
    
    py_obj.do_operation = struct.unpack_from('<?', base_data, 0)[0]
    
    
    
    # Processing: posatt (single)
    
    
    nested_base_data = base_data[8:56]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.posatt = pdu_to_py_Twist(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_ManualPosAttControl(py_obj: ManualPosAttControl) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 56
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: do_operation (single)
    
    
    struct.pack_into('<?', base_buffer, 0, py_obj.do_operation)
    
    
    
    # Processing: posatt (single)
    
    
    nested_pdu_bytes = py_to_pdu_Twist(py_obj.posatt)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[8:56] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
