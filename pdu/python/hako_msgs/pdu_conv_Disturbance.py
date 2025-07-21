
import struct
from .pdu_pytype_Disturbance import Disturbance
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..hako_msgs.pdu_conv_DisturbanceTemperature import pdu_to_py_, py_to_pdu_

from ..hako_msgs.pdu_conv_DisturbanceWind import pdu_to_py_, py_to_pdu_

from ..hako_msgs.pdu_conv_DisturbanceAtm import pdu_to_py_, py_to_pdu_

from ..hako_msgs.pdu_conv_DisturbanceBoundary import pdu_to_py_, py_to_pdu_


def pdu_to_py_Disturbance(pdu_bytes: bytes) -> Disturbance:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Disturbance()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: d_temp (single)
    
    
    nested_base_data = base_data[0:8]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.d_temp = pdu_to_py_DisturbanceTemperature(nested_pdu_bytes)
    
    
    
    # Processing: d_wind (single)
    
    
    nested_base_data = base_data[8:32]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.d_wind = pdu_to_py_DisturbanceWind(nested_pdu_bytes)
    
    
    
    # Processing: d_atm (single)
    
    
    nested_base_data = base_data[32:40]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.d_atm = pdu_to_py_DisturbanceAtm(nested_pdu_bytes)
    
    
    
    # Processing: d_boundary (single)
    
    
    nested_base_data = base_data[40:88]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.d_boundary = pdu_to_py_DisturbanceBoundary(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_Disturbance(py_obj: Disturbance) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 88
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: d_temp (single)
    
    
    nested_pdu_bytes = py_to_pdu_DisturbanceTemperature(py_obj.d_temp)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:8] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: d_wind (single)
    
    
    nested_pdu_bytes = py_to_pdu_DisturbanceWind(py_obj.d_wind)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[8:32] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: d_atm (single)
    
    
    nested_pdu_bytes = py_to_pdu_DisturbanceAtm(py_obj.d_atm)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[32:40] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: d_boundary (single)
    
    
    nested_pdu_bytes = py_to_pdu_DisturbanceBoundary(py_obj.d_boundary)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[40:88] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
