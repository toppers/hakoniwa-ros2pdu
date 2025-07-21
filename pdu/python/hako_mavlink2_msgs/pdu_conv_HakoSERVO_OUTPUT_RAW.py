
import struct
from .pdu_pytype_HakoSERVO_OUTPUT_RAW import HakoSERVO_OUTPUT_RAW
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoSERVO_OUTPUT_RAW(pdu_bytes: bytes) -> HakoSERVO_OUTPUT_RAW:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoSERVO_OUTPUT_RAW()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<I', base_data, 0)[0]
    
    
    
    # Processing: port (single)
    
    
    py_obj.port = struct.unpack_from('<B', base_data, 4)[0]
    
    
    
    # Processing: servo1_raw (single)
    
    
    py_obj.servo1_raw = struct.unpack_from('<H', base_data, 6)[0]
    
    
    
    # Processing: servo2_raw (single)
    
    
    py_obj.servo2_raw = struct.unpack_from('<H', base_data, 8)[0]
    
    
    
    # Processing: servo3_raw (single)
    
    
    py_obj.servo3_raw = struct.unpack_from('<H', base_data, 10)[0]
    
    
    
    # Processing: servo4_raw (single)
    
    
    py_obj.servo4_raw = struct.unpack_from('<H', base_data, 12)[0]
    
    
    
    # Processing: servo5_raw (single)
    
    
    py_obj.servo5_raw = struct.unpack_from('<H', base_data, 14)[0]
    
    
    
    # Processing: servo6_raw (single)
    
    
    py_obj.servo6_raw = struct.unpack_from('<H', base_data, 16)[0]
    
    
    
    # Processing: servo7_raw (single)
    
    
    py_obj.servo7_raw = struct.unpack_from('<H', base_data, 18)[0]
    
    
    
    # Processing: servo8_raw (single)
    
    
    py_obj.servo8_raw = struct.unpack_from('<H', base_data, 20)[0]
    
    
    
    # Processing: servo9_raw (single)
    
    
    py_obj.servo9_raw = struct.unpack_from('<H', base_data, 22)[0]
    
    
    
    # Processing: servo10_raw (single)
    
    
    py_obj.servo10_raw = struct.unpack_from('<H', base_data, 24)[0]
    
    
    
    # Processing: servo11_raw (single)
    
    
    py_obj.servo11_raw = struct.unpack_from('<H', base_data, 26)[0]
    
    
    
    # Processing: servo12_raw (single)
    
    
    py_obj.servo12_raw = struct.unpack_from('<H', base_data, 28)[0]
    
    
    
    # Processing: servo13_raw (single)
    
    
    py_obj.servo13_raw = struct.unpack_from('<H', base_data, 30)[0]
    
    
    
    # Processing: servo14_raw (single)
    
    
    py_obj.servo14_raw = struct.unpack_from('<H', base_data, 32)[0]
    
    
    
    # Processing: servo15_raw (single)
    
    
    py_obj.servo15_raw = struct.unpack_from('<H', base_data, 34)[0]
    
    
    
    # Processing: servo16_raw (single)
    
    
    py_obj.servo16_raw = struct.unpack_from('<H', base_data, 36)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoSERVO_OUTPUT_RAW(py_obj: HakoSERVO_OUTPUT_RAW) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 38
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<I', base_buffer, 0, py_obj.time_usec)
    
    
    
    # Processing: port (single)
    
    
    struct.pack_into('<B', base_buffer, 4, py_obj.port)
    
    
    
    # Processing: servo1_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 6, py_obj.servo1_raw)
    
    
    
    # Processing: servo2_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 8, py_obj.servo2_raw)
    
    
    
    # Processing: servo3_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 10, py_obj.servo3_raw)
    
    
    
    # Processing: servo4_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 12, py_obj.servo4_raw)
    
    
    
    # Processing: servo5_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 14, py_obj.servo5_raw)
    
    
    
    # Processing: servo6_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 16, py_obj.servo6_raw)
    
    
    
    # Processing: servo7_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 18, py_obj.servo7_raw)
    
    
    
    # Processing: servo8_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 20, py_obj.servo8_raw)
    
    
    
    # Processing: servo9_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 22, py_obj.servo9_raw)
    
    
    
    # Processing: servo10_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 24, py_obj.servo10_raw)
    
    
    
    # Processing: servo11_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 26, py_obj.servo11_raw)
    
    
    
    # Processing: servo12_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 28, py_obj.servo12_raw)
    
    
    
    # Processing: servo13_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 30, py_obj.servo13_raw)
    
    
    
    # Processing: servo14_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 32, py_obj.servo14_raw)
    
    
    
    # Processing: servo15_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 34, py_obj.servo15_raw)
    
    
    
    # Processing: servo16_raw (single)
    
    
    struct.pack_into('<H', base_buffer, 36, py_obj.servo16_raw)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
