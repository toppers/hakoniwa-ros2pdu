
import struct
from .pdu_pytype_Point import Point
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Point(pdu_bytes: bytes) -> Point:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Point()

    # 各フィールドをオフセット情報に基づいてデコード
    # array_type: single 
    # data_type: primitive 
    # member_name: x 
    # type_name: float64 
    # offset: 0 size: 8 
    # array_len: 1
    py_obj.x = struct.unpack_from('<d', base_data, 0)[0]
        
    
    # array_type: single 
    # data_type: primitive 
    # member_name: y 
    # type_name: float64 
    # offset: 8 size: 8 
    # array_len: 1
    py_obj.y = struct.unpack_from('<d', base_data, 8)[0]
        
    
    # array_type: single 
    # data_type: primitive 
    # member_name: z 
    # type_name: float64 
    # offset: 16 size: 8 
    # array_len: 1
    py_obj.z = struct.unpack_from('<d', base_data, 16)[0]
        
    return py_obj

def py_to_pdu_Point(py_obj: Point) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 24
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: x (single)
    
    
    struct.pack_into('<d', base_buffer, 0, py_obj.x)
    
    
    
    # Processing: y (single)
    
    
    struct.pack_into('<d', base_buffer, 8, py_obj.y)
    
    
    
    # Processing: z (single)
    
    
    struct.pack_into('<d', base_buffer, 16, py_obj.z)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
