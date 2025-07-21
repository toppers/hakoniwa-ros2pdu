
import struct
from .pdu_pytype_HakoHilGps import HakoHilGps
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoHilGps(pdu_bytes: bytes) -> HakoHilGps:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoHilGps()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    # Processing: lat (single)
    
    
    py_obj.lat = struct.unpack_from('<i', base_data, 8)[0]
    
    
    
    # Processing: lon (single)
    
    
    py_obj.lon = struct.unpack_from('<i', base_data, 12)[0]
    
    
    
    # Processing: alt (single)
    
    
    py_obj.alt = struct.unpack_from('<i', base_data, 16)[0]
    
    
    
    # Processing: eph (single)
    
    
    py_obj.eph = struct.unpack_from('<H', base_data, 20)[0]
    
    
    
    # Processing: epv (single)
    
    
    py_obj.epv = struct.unpack_from('<H', base_data, 22)[0]
    
    
    
    # Processing: vel (single)
    
    
    py_obj.vel = struct.unpack_from('<H', base_data, 24)[0]
    
    
    
    # Processing: vn (single)
    
    
    py_obj.vn = struct.unpack_from('<h', base_data, 26)[0]
    
    
    
    # Processing: ve (single)
    
    
    py_obj.ve = struct.unpack_from('<h', base_data, 28)[0]
    
    
    
    # Processing: vd (single)
    
    
    py_obj.vd = struct.unpack_from('<h', base_data, 30)[0]
    
    
    
    # Processing: cog (single)
    
    
    py_obj.cog = struct.unpack_from('<H', base_data, 32)[0]
    
    
    
    # Processing: satellites_visible (single)
    
    
    py_obj.satellites_visible = struct.unpack_from('<B', base_data, 34)[0]
    
    
    
    # Processing: id (single)
    
    
    py_obj.id = struct.unpack_from('<B', base_data, 35)[0]
    
    
    
    # Processing: yaw (single)
    
    
    py_obj.yaw = struct.unpack_from('<B', base_data, 36)[0]
    
    
    
    # Processing: fix_type (single)
    
    
    py_obj.fix_type = struct.unpack_from('<B', base_data, 37)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoHilGps(py_obj: HakoHilGps) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 38
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_usec)
    
    
    
    # Processing: lat (single)
    
    
    struct.pack_into('<i', base_buffer, 8, py_obj.lat)
    
    
    
    # Processing: lon (single)
    
    
    struct.pack_into('<i', base_buffer, 12, py_obj.lon)
    
    
    
    # Processing: alt (single)
    
    
    struct.pack_into('<i', base_buffer, 16, py_obj.alt)
    
    
    
    # Processing: eph (single)
    
    
    struct.pack_into('<H', base_buffer, 20, py_obj.eph)
    
    
    
    # Processing: epv (single)
    
    
    struct.pack_into('<H', base_buffer, 22, py_obj.epv)
    
    
    
    # Processing: vel (single)
    
    
    struct.pack_into('<H', base_buffer, 24, py_obj.vel)
    
    
    
    # Processing: vn (single)
    
    
    struct.pack_into('<h', base_buffer, 26, py_obj.vn)
    
    
    
    # Processing: ve (single)
    
    
    struct.pack_into('<h', base_buffer, 28, py_obj.ve)
    
    
    
    # Processing: vd (single)
    
    
    struct.pack_into('<h', base_buffer, 30, py_obj.vd)
    
    
    
    # Processing: cog (single)
    
    
    struct.pack_into('<H', base_buffer, 32, py_obj.cog)
    
    
    
    # Processing: satellites_visible (single)
    
    
    struct.pack_into('<B', base_buffer, 34, py_obj.satellites_visible)
    
    
    
    # Processing: id (single)
    
    
    struct.pack_into('<B', base_buffer, 35, py_obj.id)
    
    
    
    # Processing: yaw (single)
    
    
    struct.pack_into('<B', base_buffer, 36, py_obj.yaw)
    
    
    
    # Processing: fix_type (single)
    
    
    struct.pack_into('<B', base_buffer, 37, py_obj.fix_type)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
