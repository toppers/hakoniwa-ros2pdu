
import struct
from .pdu_pytype_ServiceResponseHeader import ServiceResponseHeader
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_ServiceResponseHeader(pdu_bytes: bytes) -> ServiceResponseHeader:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ServiceResponseHeader()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: request_id (single)
    
    
    py_obj.request_id = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: service_name (single)
    
    
    py_obj.service_name = struct.unpack_from('<', base_data, 4)[0]
    
    
    
    # Processing: client_name (single)
    
    
    py_obj.client_name = struct.unpack_from('<', base_data, 132)[0]
    
    
    
    # Processing: status (single)
    
    
    py_obj.status = struct.unpack_from('<B', base_data, 260)[0]
    
    
    
    # Processing: processing_percentage (single)
    
    
    py_obj.processing_percentage = struct.unpack_from('<B', base_data, 261)[0]
    
    
    
    # Processing: result_code (single)
    
    
    py_obj.result_code = struct.unpack_from('<i', base_data, 264)[0]
    
    
    
    return py_obj

def py_to_pdu_ServiceResponseHeader(py_obj: ServiceResponseHeader) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 268
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: request_id (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.request_id)
    
    
    
    # Processing: service_name (single)
    
    
    struct.pack_into('<', base_buffer, 4, py_obj.service_name)
    
    
    
    # Processing: client_name (single)
    
    
    struct.pack_into('<', base_buffer, 132, py_obj.client_name)
    
    
    
    # Processing: status (single)
    
    
    struct.pack_into('<B', base_buffer, 260, py_obj.status)
    
    
    
    # Processing: processing_percentage (single)
    
    
    struct.pack_into('<B', base_buffer, 261, py_obj.processing_percentage)
    
    
    
    # Processing: result_code (single)
    
    
    struct.pack_into('<i', base_buffer, 264, py_obj.result_code)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
