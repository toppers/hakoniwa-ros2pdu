
import struct
from .pdu_pytype_AddTwoIntsResponse import AddTwoIntsResponse
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_AddTwoIntsResponse(pdu_bytes: bytes) -> AddTwoIntsResponse:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = AddTwoIntsResponse()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: sum (single)
    
    
    py_obj.sum = struct.unpack_from('<q', base_data, 0)[0]
    
    
    
    return py_obj

def py_to_pdu_AddTwoIntsResponse(py_obj: AddTwoIntsResponse) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: sum (single)
    
    
    struct.pack_into('<q', base_buffer, 0, py_obj.sum)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
