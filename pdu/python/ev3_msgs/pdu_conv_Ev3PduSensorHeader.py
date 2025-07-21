
import struct
from .pdu_pytype_Ev3PduSensorHeader import Ev3PduSensorHeader
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_Ev3PduSensorHeader(pdu_bytes: bytes) -> Ev3PduSensorHeader:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Ev3PduSensorHeader()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: name (single)
    
    
    py_obj.name = struct.unpack_from('<', base_data, 0)[0]
    
    
    
    # Processing: version (single)
    
    
    py_obj.version = struct.unpack_from('<I', base_data, 128)[0]
    
    
    
    # Processing: hakoniwa_time (single)
    
    
    py_obj.hakoniwa_time = struct.unpack_from('<q', base_data, 136)[0]
    
    
    
    # Processing: ext_off (single)
    
    
    py_obj.ext_off = struct.unpack_from('<I', base_data, 144)[0]
    
    
    
    # Processing: ext_size (single)
    
    
    py_obj.ext_size = struct.unpack_from('<I', base_data, 148)[0]
    
    
    
    return py_obj

def py_to_pdu_Ev3PduSensorHeader(py_obj: Ev3PduSensorHeader) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 152
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: name (single)
    
    
    struct.pack_into('<', base_buffer, 0, py_obj.name)
    
    
    
    # Processing: version (single)
    
    
    struct.pack_into('<I', base_buffer, 128, py_obj.version)
    
    
    
    # Processing: hakoniwa_time (single)
    
    
    struct.pack_into('<q', base_buffer, 136, py_obj.hakoniwa_time)
    
    
    
    # Processing: ext_off (single)
    
    
    struct.pack_into('<I', base_buffer, 144, py_obj.ext_off)
    
    
    
    # Processing: ext_size (single)
    
    
    struct.pack_into('<I', base_buffer, 148, py_obj.ext_size)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
