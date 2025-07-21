
import struct
from .pdu_pytype_PointField import PointField
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_PointField(pdu_bytes: bytes) -> PointField:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = PointField()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: name (single)
    
    
    py_obj.name = struct.unpack_from('<', base_data, 0)[0]
    
    
    
    # Processing: offset (single)
    
    
    py_obj.offset = struct.unpack_from('<I', base_data, 128)[0]
    
    
    
    # Processing: datatype (single)
    
    
    py_obj.datatype = struct.unpack_from('<B', base_data, 132)[0]
    
    
    
    # Processing: count (single)
    
    
    py_obj.count = struct.unpack_from('<I', base_data, 136)[0]
    
    
    
    return py_obj

def py_to_pdu_PointField(py_obj: PointField) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 140
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: name (single)
    
    
    struct.pack_into('<', base_buffer, 0, py_obj.name)
    
    
    
    # Processing: offset (single)
    
    
    struct.pack_into('<I', base_buffer, 128, py_obj.offset)
    
    
    
    # Processing: datatype (single)
    
    
    struct.pack_into('<B', base_buffer, 132, py_obj.datatype)
    
    
    
    # Processing: count (single)
    
    
    struct.pack_into('<I', base_buffer, 136, py_obj.count)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
