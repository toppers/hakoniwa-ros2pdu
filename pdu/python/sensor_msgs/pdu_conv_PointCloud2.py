
import struct
from .pdu_pytype_PointCloud2 import PointCloud2
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..sensor_msgs.pdu_conv_PointField import pdu_to_py_, py_to_pdu_


def pdu_to_py_PointCloud2(pdu_bytes: bytes) -> PointCloud2:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = PointCloud2()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: height (single)
    
    
    py_obj.height = struct.unpack_from('<I', base_data, 136)[0]
    
    
    
    # Processing: width (single)
    
    
    py_obj.width = struct.unpack_from('<I', base_data, 140)[0]
    
    
    
    # Processing: fields (varray)
    
    ref_offset = 144
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.fields = []
    element_size = 140
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        nested_pdu_bytes = heap_data[current_heap_offset:]
        val = pdu_to_py_PointField(nested_pdu_bytes)
        py_obj.fields.append(val)
        # Move offset by the total size of the nested PDU
        _m, _b, nested_heap = unpack_pdu(nested_pdu_bytes)
        current_heap_offset += _m['total_size']
    
    
    
    # Processing: is_bigendian (single)
    
    
    py_obj.is_bigendian = struct.unpack_from('<?', base_data, 152)[0]
    
    
    
    # Processing: point_step (single)
    
    
    py_obj.point_step = struct.unpack_from('<I', base_data, 156)[0]
    
    
    
    # Processing: row_step (single)
    
    
    py_obj.row_step = struct.unpack_from('<I', base_data, 160)[0]
    
    
    
    # Processing: data (varray)
    
    ref_offset = 164
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 1
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<B', heap_data, current_heap_offset)[0]
        py_obj.data.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: is_dense (single)
    
    
    py_obj.is_dense = struct.unpack_from('<?', base_data, 172)[0]
    
    
    
    return py_obj

def py_to_pdu_PointCloud2(py_obj: PointCloud2) -> bytes:
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
    
    
    
    # Processing: height (single)
    
    
    struct.pack_into('<I', base_buffer, 136, py_obj.height)
    
    
    
    # Processing: width (single)
    
    
    struct.pack_into('<I', base_buffer, 140, py_obj.width)
    
    
    
    # Processing: fields (varray)
    
    array_len = len(py_obj.fields)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    # 構造体の可変長配列
    for element in py_obj.fields:
        nested_pdu_bytes = py_to_pdu_PointField(element)
        elements_heap_bytes += nested_pdu_bytes
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 144, array_len, heap_offset)
    
    
    # Processing: is_bigendian (single)
    
    
    struct.pack_into('<?', base_buffer, 152, py_obj.is_bigendian)
    
    
    
    # Processing: point_step (single)
    
    
    struct.pack_into('<I', base_buffer, 156, py_obj.point_step)
    
    
    
    # Processing: row_step (single)
    
    
    struct.pack_into('<I', base_buffer, 160, py_obj.row_step)
    
    
    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.data:
        elements_heap_bytes += struct.pack('<B', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 164, array_len, heap_offset)
    
    
    # Processing: is_dense (single)
    
    
    struct.pack_into('<?', base_buffer, 172, py_obj.is_dense)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
