
import struct
from .pdu_pytype_HakoStatusMagnetHolder import HakoStatusMagnetHolder
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoStatusMagnetHolder(pdu_bytes: bytes) -> HakoStatusMagnetHolder:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoStatusMagnetHolder()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: magnet_on (single)
    
    
    py_obj.magnet_on = struct.unpack_from('<?', base_data, 0)[0]
    
    
    
    # Processing: contact_on (single)
    
    
    py_obj.contact_on = struct.unpack_from('<?', base_data, 4)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoStatusMagnetHolder(py_obj: HakoStatusMagnetHolder) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 8
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: magnet_on (single)
    
    
    struct.pack_into('<?', base_buffer, 0, py_obj.magnet_on)
    
    
    
    # Processing: contact_on (single)
    
    
    struct.pack_into('<?', base_buffer, 4, py_obj.contact_on)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
