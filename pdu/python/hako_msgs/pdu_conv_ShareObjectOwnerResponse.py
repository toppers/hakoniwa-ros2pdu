
import struct
from .pdu_pytype_ShareObjectOwnerResponse import ShareObjectOwnerResponse
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_ShareObjectOwnerResponse(pdu_bytes: bytes) -> ShareObjectOwnerResponse:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ShareObjectOwnerResponse()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: object_name (single)
    
    
    py_obj.object_name = struct.unpack_from('<', base_data, 0)[0]
    
    
    
    # Processing: request_type (single)
    
    
    py_obj.request_type = struct.unpack_from('<I', base_data, 128)[0]
    
    
    
    # Processing: owner_id (single)
    
    
    py_obj.owner_id = struct.unpack_from('<I', base_data, 132)[0]
    
    
    
    # Processing: accepted (single)
    
    
    py_obj.accepted = struct.unpack_from('<?', base_data, 136)[0]
    
    
    
    return py_obj

def py_to_pdu_ShareObjectOwnerResponse(py_obj: ShareObjectOwnerResponse) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 140
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: object_name (single)
    
    
    struct.pack_into('<', base_buffer, 0, py_obj.object_name)
    
    
    
    # Processing: request_type (single)
    
    
    struct.pack_into('<I', base_buffer, 128, py_obj.request_type)
    
    
    
    # Processing: owner_id (single)
    
    
    struct.pack_into('<I', base_buffer, 132, py_obj.owner_id)
    
    
    
    # Processing: accepted (single)
    
    
    struct.pack_into('<?', base_buffer, 136, py_obj.accepted)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
