
import struct
from .pdu_pytype_HakoHilActuatorControls import HakoHilActuatorControls
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoHilActuatorControls(pdu_bytes: bytes) -> HakoHilActuatorControls:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoHilActuatorControls()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    # Processing: controls (array)
    
    py_obj.controls = []
    element_size = 4
    for i in range(16):
        element_offset = 8 + i * element_size
    
        val = struct.unpack_from('<f', base_data, element_offset)[0]
        py_obj.controls.append(val)
    
    
    
    # Processing: mode (single)
    
    
    py_obj.mode = struct.unpack_from('<B', base_data, 72)[0]
    
    
    
    # Processing: flags (single)
    
    
    py_obj.flags = struct.unpack_from('<Q', base_data, 80)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoHilActuatorControls(py_obj: HakoHilActuatorControls) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 88
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_usec)
    
    
    
    # Processing: controls (array)
    
    element_size = 4
    for i, element in enumerate(py_obj.controls):
        if i >= 16: break
        element_offset = 8 + i * element_size
    
        struct.pack_into('<f', base_buffer, element_offset, element)
    
    
    
    # Processing: mode (single)
    
    
    struct.pack_into('<B', base_buffer, 72, py_obj.mode)
    
    
    
    # Processing: flags (single)
    
    
    struct.pack_into('<Q', base_buffer, 80, py_obj.flags)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
