
import struct
from .pdu_pytype_ColorRGBA import ColorRGBA
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_ColorRGBA(pdu_bytes: bytes) -> ColorRGBA:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = ColorRGBA()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: r (single)
    
    
    py_obj.r = struct.unpack_from('<f', base_data, 0)[0]
    
    
    
    # Processing: g (single)
    
    
    py_obj.g = struct.unpack_from('<f', base_data, 4)[0]
    
    
    
    # Processing: b (single)
    
    
    py_obj.b = struct.unpack_from('<f', base_data, 8)[0]
    
    
    
    # Processing: a (single)
    
    
    py_obj.a = struct.unpack_from('<f', base_data, 12)[0]
    
    
    
    return py_obj

def py_to_pdu_ColorRGBA(py_obj: ColorRGBA) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 16
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: r (single)
    
    
    struct.pack_into('<f', base_buffer, 0, py_obj.r)
    
    
    
    # Processing: g (single)
    
    
    struct.pack_into('<f', base_buffer, 4, py_obj.g)
    
    
    
    # Processing: b (single)
    
    
    struct.pack_into('<f', base_buffer, 8, py_obj.b)
    
    
    
    # Processing: a (single)
    
    
    struct.pack_into('<f', base_buffer, 12, py_obj.a)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
