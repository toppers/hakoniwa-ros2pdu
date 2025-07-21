
import struct
from .pdu_pytype_HakoGLOBAL_POSITION_INT import HakoGLOBAL_POSITION_INT
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoGLOBAL_POSITION_INT(pdu_bytes: bytes) -> HakoGLOBAL_POSITION_INT:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoGLOBAL_POSITION_INT()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_boot_ms (single)
    
    
    py_obj.time_boot_ms = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: lat (single)
    
    
    py_obj.lat = struct.unpack_from('<i', base_data, 4)[0]
    
    
    
    # Processing: lon (single)
    
    
    py_obj.lon = struct.unpack_from('<i', base_data, 8)[0]
    
    
    
    # Processing: alt (single)
    
    
    py_obj.alt = struct.unpack_from('<i', base_data, 12)[0]
    
    
    
    # Processing: relative_alt (single)
    
    
    py_obj.relative_alt = struct.unpack_from('<i', base_data, 16)[0]
    
    
    
    # Processing: vx (single)
    
    
    py_obj.vx = struct.unpack_from('<h', base_data, 20)[0]
    
    
    
    # Processing: vy (single)
    
    
    py_obj.vy = struct.unpack_from('<h', base_data, 22)[0]
    
    
    
    # Processing: vz (single)
    
    
    py_obj.vz = struct.unpack_from('<h', base_data, 24)[0]
    
    
    
    # Processing: hdg (single)
    
    
    py_obj.hdg = struct.unpack_from('<H', base_data, 26)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoGLOBAL_POSITION_INT(py_obj: HakoGLOBAL_POSITION_INT) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 28
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_boot_ms (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.time_boot_ms)
    
    
    
    # Processing: lat (single)
    
    
    struct.pack_into('<i', base_buffer, 4, py_obj.lat)
    
    
    
    # Processing: lon (single)
    
    
    struct.pack_into('<i', base_buffer, 8, py_obj.lon)
    
    
    
    # Processing: alt (single)
    
    
    struct.pack_into('<i', base_buffer, 12, py_obj.alt)
    
    
    
    # Processing: relative_alt (single)
    
    
    struct.pack_into('<i', base_buffer, 16, py_obj.relative_alt)
    
    
    
    # Processing: vx (single)
    
    
    struct.pack_into('<h', base_buffer, 20, py_obj.vx)
    
    
    
    # Processing: vy (single)
    
    
    struct.pack_into('<h', base_buffer, 22, py_obj.vy)
    
    
    
    # Processing: vz (single)
    
    
    struct.pack_into('<h', base_buffer, 24, py_obj.vz)
    
    
    
    # Processing: hdg (single)
    
    
    struct.pack_into('<H', base_buffer, 26, py_obj.hdg)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
