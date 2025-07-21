
import struct
from .pdu_pytype_RegionOfInterest import RegionOfInterest
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_RegionOfInterest(pdu_bytes: bytes) -> RegionOfInterest:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = RegionOfInterest()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: x_offset (single)
    
    
    py_obj.x_offset = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: y_offset (single)
    
    
    py_obj.y_offset = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: height (single)
    
    
    py_obj.height = struct.unpack_from('<I', base_data, 8)[0]
    
    
    
    # Processing: width (single)
    
    
    py_obj.width = struct.unpack_from('<I', base_data, 12)[0]
    
    
    
    # Processing: do_rectify (single)
    
    
    py_obj.do_rectify = struct.unpack_from('<?', base_data, 16)[0]
    
    
    
    return py_obj

def py_to_pdu_RegionOfInterest(py_obj: RegionOfInterest) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 20
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: x_offset (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.x_offset)
    
    
    
    # Processing: y_offset (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.y_offset)
    
    
    
    # Processing: height (single)
    
    
    struct.pack_into('<I', base_buffer, 8, py_obj.height)
    
    
    
    # Processing: width (single)
    
    
    struct.pack_into('<I', base_buffer, 12, py_obj.width)
    
    
    
    # Processing: do_rectify (single)
    
    
    struct.pack_into('<?', base_buffer, 16, py_obj.do_rectify)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
