
import struct
from .pdu_pytype_ServiceRequestHeader import ServiceRequestHeader
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_ServiceRequestHeader(pdu_bytes: bytes) -> ServiceRequestHeader:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ServiceRequestHeader()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: request_id (single)
    
    
    py_obj.request_id = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: service_name (single)
    
    
    py_obj.service_name = struct.unpack_from('<', base_data, 4)[0]
    
    
    
    # Processing: client_name (single)
    
    
    py_obj.client_name = struct.unpack_from('<', base_data, 132)[0]
    
    
    
    # Processing: opcode (single)
    
    
    py_obj.opcode = struct.unpack_from('<B', base_data, 260)[0]
    
    
    
    # Processing: status_poll_interval_msec (single)
    
    
    py_obj.status_poll_interval_msec = struct.unpack_from('<i', base_data, 264)[0]
    
    
    
    return py_obj

def py_to_pdu_ServiceRequestHeader(py_obj: ServiceRequestHeader) -> bytes:
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
    
    
    
    # Processing: opcode (single)
    
    
    struct.pack_into('<B', base_buffer, 260, py_obj.opcode)
    
    
    
    # Processing: status_poll_interval_msec (single)
    
    
    struct.pack_into('<i', base_buffer, 264, py_obj.status_poll_interval_msec)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
