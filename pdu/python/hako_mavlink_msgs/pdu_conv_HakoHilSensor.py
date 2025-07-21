
import struct
from .pdu_pytype_HakoHilSensor import HakoHilSensor
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoHilSensor(pdu_bytes: bytes) -> HakoHilSensor:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoHilSensor()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    # Processing: xacc (single)
    
    
    py_obj.xacc = struct.unpack_from('<f', base_data, 8)[0]
    
    
    
    # Processing: yacc (single)
    
    
    py_obj.yacc = struct.unpack_from('<f', base_data, 12)[0]
    
    
    
    # Processing: zacc (single)
    
    
    py_obj.zacc = struct.unpack_from('<f', base_data, 16)[0]
    
    
    
    # Processing: xgyro (single)
    
    
    py_obj.xgyro = struct.unpack_from('<f', base_data, 20)[0]
    
    
    
    # Processing: ygyro (single)
    
    
    py_obj.ygyro = struct.unpack_from('<f', base_data, 24)[0]
    
    
    
    # Processing: zgyro (single)
    
    
    py_obj.zgyro = struct.unpack_from('<f', base_data, 28)[0]
    
    
    
    # Processing: xmag (single)
    
    
    py_obj.xmag = struct.unpack_from('<f', base_data, 32)[0]
    
    
    
    # Processing: ymag (single)
    
    
    py_obj.ymag = struct.unpack_from('<f', base_data, 36)[0]
    
    
    
    # Processing: zmag (single)
    
    
    py_obj.zmag = struct.unpack_from('<f', base_data, 40)[0]
    
    
    
    # Processing: abs_pressure (single)
    
    
    py_obj.abs_pressure = struct.unpack_from('<f', base_data, 44)[0]
    
    
    
    # Processing: diff_pressure (single)
    
    
    py_obj.diff_pressure = struct.unpack_from('<f', base_data, 48)[0]
    
    
    
    # Processing: pressure_alt (single)
    
    
    py_obj.pressure_alt = struct.unpack_from('<f', base_data, 52)[0]
    
    
    
    # Processing: temperature (single)
    
    
    py_obj.temperature = struct.unpack_from('<f', base_data, 56)[0]
    
    
    
    # Processing: fields_updated (single)
    
    
    py_obj.fields_updated = struct.unpack_from('<I', base_data, 60)[0]
    
    
    
    # Processing: id (single)
    
    
    py_obj.id = struct.unpack_from('<B', base_data, 64)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoHilSensor(py_obj: HakoHilSensor) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 65
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_usec)
    
    
    
    # Processing: xacc (single)
    
    
    struct.pack_into('<f', base_buffer, 8, py_obj.xacc)
    
    
    
    # Processing: yacc (single)
    
    
    struct.pack_into('<f', base_buffer, 12, py_obj.yacc)
    
    
    
    # Processing: zacc (single)
    
    
    struct.pack_into('<f', base_buffer, 16, py_obj.zacc)
    
    
    
    # Processing: xgyro (single)
    
    
    struct.pack_into('<f', base_buffer, 20, py_obj.xgyro)
    
    
    
    # Processing: ygyro (single)
    
    
    struct.pack_into('<f', base_buffer, 24, py_obj.ygyro)
    
    
    
    # Processing: zgyro (single)
    
    
    struct.pack_into('<f', base_buffer, 28, py_obj.zgyro)
    
    
    
    # Processing: xmag (single)
    
    
    struct.pack_into('<f', base_buffer, 32, py_obj.xmag)
    
    
    
    # Processing: ymag (single)
    
    
    struct.pack_into('<f', base_buffer, 36, py_obj.ymag)
    
    
    
    # Processing: zmag (single)
    
    
    struct.pack_into('<f', base_buffer, 40, py_obj.zmag)
    
    
    
    # Processing: abs_pressure (single)
    
    
    struct.pack_into('<f', base_buffer, 44, py_obj.abs_pressure)
    
    
    
    # Processing: diff_pressure (single)
    
    
    struct.pack_into('<f', base_buffer, 48, py_obj.diff_pressure)
    
    
    
    # Processing: pressure_alt (single)
    
    
    struct.pack_into('<f', base_buffer, 52, py_obj.pressure_alt)
    
    
    
    # Processing: temperature (single)
    
    
    struct.pack_into('<f', base_buffer, 56, py_obj.temperature)
    
    
    
    # Processing: fields_updated (single)
    
    
    struct.pack_into('<I', base_buffer, 60, py_obj.fields_updated)
    
    
    
    # Processing: id (single)
    
    
    struct.pack_into('<B', base_buffer, 64, py_obj.id)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
