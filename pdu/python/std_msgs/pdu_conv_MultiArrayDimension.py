
import struct
from .pdu_pytype_MultiArrayDimension import MultiArrayDimension
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_MultiArrayDimension(pdu_bytes: bytes) -> MultiArrayDimension:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = MultiArrayDimension()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: label (single)
    
    
    py_obj.label = struct.unpack_from('<', base_data, 0)[0]
    
    
    
    # Processing: size (single)
    
    
    py_obj.size = struct.unpack_from('<I', base_data, 128)[0]
    
    
    
    # Processing: stride (single)
    
    
    py_obj.stride = struct.unpack_from('<I', base_data, 132)[0]
    
    
    
    return py_obj

def py_to_pdu_MultiArrayDimension(py_obj: MultiArrayDimension) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 136
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: label (single)
    
    
    struct.pack_into('<', base_buffer, 0, py_obj.label)
    
    
    
    # Processing: size (single)
    
    
    struct.pack_into('<I', base_buffer, 128, py_obj.size)
    
    
    
    # Processing: stride (single)
    
    
    struct.pack_into('<I', base_buffer, 132, py_obj.stride)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
