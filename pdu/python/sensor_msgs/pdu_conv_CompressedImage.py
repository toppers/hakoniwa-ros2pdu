
import struct
from .pdu_pytype_CompressedImage import CompressedImage
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_


def pdu_to_py_CompressedImage(pdu_bytes: bytes) -> CompressedImage:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = CompressedImage()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: format (single)
    
    
    py_obj.format = struct.unpack_from('<', base_data, 136)[0]
    
    
    
    # Processing: data (varray)
    
    ref_offset = 264
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.data = []
    element_size = 1
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<B', heap_data, current_heap_offset)[0]
        py_obj.data.append(val)
        current_heap_offset += element_size
    
    
    
    return py_obj

def py_to_pdu_CompressedImage(py_obj: CompressedImage) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 265
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: format (single)
    
    
    struct.pack_into('<', base_buffer, 136, py_obj.format)
    
    
    
    # Processing: data (varray)
    
    array_len = len(py_obj.data)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.data:
        elements_heap_bytes += struct.pack('<B', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 264, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
