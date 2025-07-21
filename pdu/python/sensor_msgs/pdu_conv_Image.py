
import struct
from .pdu_pytype_Image import Image
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_


def pdu_to_py_Image(pdu_bytes: bytes) -> Image:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Image()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: height (single)
    
    
    py_obj.height = struct.unpack_from('<I', base_data, 136)[0]
    
    
    
    # Processing: width (single)
    
    
    py_obj.width = struct.unpack_from('<I', base_data, 140)[0]
    
    
    
    # Processing: encoding (single)
    
    
    py_obj.encoding = struct.unpack_from('<', base_data, 144)[0]
    
    
    
    # Processing: is_bigendian (single)
    
    
    py_obj.is_bigendian = struct.unpack_from('<B', base_data, 272)[0]
    
    
    
    # Processing: step (single)
    
    
    py_obj.step = struct.unpack_from('<I', base_data, 276)[0]
    
    
    
    # Processing: data (varray)
    
    ref_offset = 280
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 1
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<B', heap_data, current_heap_offset)[0]
        py_obj.data.append(val)
        current_heap_offset += element_size
    
    
    
    return py_obj

def py_to_pdu_Image(py_obj: Image) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 281
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
    
    
    
    # Processing: encoding (single)
    
    
    struct.pack_into('<', base_buffer, 144, py_obj.encoding)
    
    
    
    # Processing: is_bigendian (single)
    
    
    struct.pack_into('<B', base_buffer, 272, py_obj.is_bigendian)
    
    
    
    # Processing: step (single)
    
    
    struct.pack_into('<I', base_buffer, 276, py_obj.step)
    
    
    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.data:
        elements_heap_bytes += struct.pack('<B', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 280, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
