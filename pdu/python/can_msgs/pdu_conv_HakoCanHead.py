
import struct
from .pdu_pytype_HakoCanHead import HakoCanHead
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoCanHead(pdu_bytes: bytes) -> HakoCanHead:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoCanHead()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: channel (single)
    
    
    py_obj.channel = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: ide (single)
    
    
    py_obj.ide = struct.unpack_from('<I', base_data, 4)[0]
    
    
    
    # Processing: rtr (single)
    
    
    py_obj.rtr = struct.unpack_from('<I', base_data, 8)[0]
    
    
    
    # Processing: dlc (single)
    
    
    py_obj.dlc = struct.unpack_from('<I', base_data, 12)[0]
    
    
    
    # Processing: canid (single)
    
    
    py_obj.canid = struct.unpack_from('<I', base_data, 16)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoCanHead(py_obj: HakoCanHead) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 20
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: channel (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.channel)
    
    
    
    # Processing: ide (single)
    
    
    struct.pack_into('<I', base_buffer, 4, py_obj.ide)
    
    
    
    # Processing: rtr (single)
    
    
    struct.pack_into('<I', base_buffer, 8, py_obj.rtr)
    
    
    
    # Processing: dlc (single)
    
    
    struct.pack_into('<I', base_buffer, 12, py_obj.dlc)
    
    
    
    # Processing: canid (single)
    
    
    struct.pack_into('<I', base_buffer, 16, py_obj.canid)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
