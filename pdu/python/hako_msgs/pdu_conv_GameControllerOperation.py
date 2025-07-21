
import struct
from .pdu_pytype_GameControllerOperation import GameControllerOperation
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_GameControllerOperation(pdu_bytes: bytes) -> GameControllerOperation:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = GameControllerOperation()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: axis (array)
    
    py_obj.axis = []
    element_size = 8
    for i in range(6):
        element_offset = 0 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.axis.append(val)
    
    
    
    # Processing: button (array)
    
    py_obj.button = []
    element_size = 4
    for i in range(15):
        element_offset = 48 + i * element_size
    
        val = struct.unpack_from('<?', base_data, element_offset)[0]
        py_obj.button.append(val)
    
    
    
    return py_obj

def py_to_pdu_GameControllerOperation(py_obj: GameControllerOperation) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 108
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: axis (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.axis):
        if i >= 6: break
        element_offset = 0 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: button (array)
    
    element_size = 4
    for i, element in enumerate(py_obj.button):
        if i >= 15: break
        element_offset = 48 + i * element_size
    
        struct.pack_into('<?', base_buffer, element_offset, element)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
