
import struct
from .pdu_pytype_HakoDroneCmdHeader import HakoDroneCmdHeader
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoDroneCmdHeader(pdu_bytes: bytes) -> HakoDroneCmdHeader:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoDroneCmdHeader()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: request (single)
    
    
    py_obj.request = struct.unpack_from('<?', base_data, 0)[0]
    
    
    
    # Processing: result (single)
    
    
    py_obj.result = struct.unpack_from('<?', base_data, 4)[0]
    
    
    
    # Processing: result_code (single)
    
    
    py_obj.result_code = struct.unpack_from('<i', base_data, 8)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoDroneCmdHeader(py_obj: HakoDroneCmdHeader) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 12
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: request (single)
    
    
    struct.pack_into('<?', base_buffer, 0, py_obj.request)
    
    
    
    # Processing: result (single)
    
    
    struct.pack_into('<?', base_buffer, 4, py_obj.result)
    
    
    
    # Processing: result_code (single)
    
    
    struct.pack_into('<i', base_buffer, 8, py_obj.result_code)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
