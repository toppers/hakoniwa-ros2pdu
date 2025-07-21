
import struct
from .pdu_pytype_HakoBatteryStatus import HakoBatteryStatus
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoBatteryStatus(pdu_bytes: bytes) -> HakoBatteryStatus:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoBatteryStatus()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: full_voltage (single)
    
    
    py_obj.full_voltage = struct.unpack_from('<d', base_data, 0)[0]
    
    
    
    # Processing: curr_voltage (single)
    
    
    py_obj.curr_voltage = struct.unpack_from('<d', base_data, 8)[0]
    
    
    
    # Processing: curr_temp (single)
    
    
    py_obj.curr_temp = struct.unpack_from('<d', base_data, 16)[0]
    
    
    
    # Processing: status (single)
    
    
    py_obj.status = struct.unpack_from('<I', base_data, 24)[0]
    
    
    
    # Processing: cycles (single)
    
    
    py_obj.cycles = struct.unpack_from('<I', base_data, 28)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoBatteryStatus(py_obj: HakoBatteryStatus) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 32
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: full_voltage (single)
    
    
    struct.pack_into('<d', base_buffer, 0, py_obj.full_voltage)
    
    
    
    # Processing: curr_voltage (single)
    
    
    struct.pack_into('<d', base_buffer, 8, py_obj.curr_voltage)
    
    
    
    # Processing: curr_temp (single)
    
    
    struct.pack_into('<d', base_buffer, 16, py_obj.curr_temp)
    
    
    
    # Processing: status (single)
    
    
    struct.pack_into('<I', base_buffer, 24, py_obj.status)
    
    
    
    # Processing: cycles (single)
    
    
    struct.pack_into('<I', base_buffer, 28, py_obj.cycles)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
