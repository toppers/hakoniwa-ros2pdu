
import struct
from .pdu_pytype_AddTwoIntsRequest import AddTwoIntsRequest
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_AddTwoIntsRequest(pdu_bytes: bytes) -> AddTwoIntsRequest:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = AddTwoIntsRequest()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: a (single)
    
    
    py_obj.a = struct.unpack_from('<q', base_data, 0)[0]
    
    
    
    # Processing: b (single)
    
    
    py_obj.b = struct.unpack_from('<q', base_data, 8)[0]
    
    
    
    return py_obj

def py_to_pdu_AddTwoIntsRequest(py_obj: AddTwoIntsRequest) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 16
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: a (single)
    
    
    struct.pack_into('<q', base_buffer, 0, py_obj.a)
    
    
    
    # Processing: b (single)
    
    
    struct.pack_into('<q', base_buffer, 8, py_obj.b)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
