
import struct
from .pdu_pytype_LaserScan import LaserScan
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_


def pdu_to_py_LaserScan(pdu_bytes: bytes) -> LaserScan:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = LaserScan()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: angle_min (single)
    
    
    py_obj.angle_min = struct.unpack_from('<f', base_data, 136)[0]
    
    
    
    # Processing: angle_max (single)
    
    
    py_obj.angle_max = struct.unpack_from('<f', base_data, 140)[0]
    
    
    
    # Processing: angle_increment (single)
    
    
    py_obj.angle_increment = struct.unpack_from('<f', base_data, 144)[0]
    
    
    
    # Processing: time_increment (single)
    
    
    py_obj.time_increment = struct.unpack_from('<f', base_data, 148)[0]
    
    
    
    # Processing: scan_time (single)
    
    
    py_obj.scan_time = struct.unpack_from('<f', base_data, 152)[0]
    
    
    
    # Processing: range_min (single)
    
    
    py_obj.range_min = struct.unpack_from('<f', base_data, 156)[0]
    
    
    
    # Processing: range_max (single)
    
    
    py_obj.range_max = struct.unpack_from('<f', base_data, 160)[0]
    
    
    
    # Processing: ranges (varray)
    
    ref_offset = 164
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.ranges = []
    element_size = 4
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<f', heap_data, current_heap_offset)[0]
        py_obj.ranges.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: intensities (varray)
    
    ref_offset = 172
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.intensities = []
    element_size = 4
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<f', heap_data, current_heap_offset)[0]
        py_obj.intensities.append(val)
        current_heap_offset += element_size
    
    
    
    return py_obj

def py_to_pdu_LaserScan(py_obj: LaserScan) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 176
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: angle_min (single)
    
    
    struct.pack_into('<f', base_buffer, 136, py_obj.angle_min)
    
    
    
    # Processing: angle_max (single)
    
    
    struct.pack_into('<f', base_buffer, 140, py_obj.angle_max)
    
    
    
    # Processing: angle_increment (single)
    
    
    struct.pack_into('<f', base_buffer, 144, py_obj.angle_increment)
    
    
    
    # Processing: time_increment (single)
    
    
    struct.pack_into('<f', base_buffer, 148, py_obj.time_increment)
    
    
    
    # Processing: scan_time (single)
    
    
    struct.pack_into('<f', base_buffer, 152, py_obj.scan_time)
    
    
    
    # Processing: range_min (single)
    
    
    struct.pack_into('<f', base_buffer, 156, py_obj.range_min)
    
    
    
    # Processing: range_max (single)
    
    
    struct.pack_into('<f', base_buffer, 160, py_obj.range_max)
    
    
    
    # Processing: ranges (varray)
    
    array_len = len(py_obj.ranges)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.ranges:
        elements_heap_bytes += struct.pack('<f', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 164, array_len, heap_offset)
    
    
    # Processing: intensities (varray)
    
    array_len = len(py_obj.intensities)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.intensities:
        elements_heap_bytes += struct.pack('<f', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 172, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
