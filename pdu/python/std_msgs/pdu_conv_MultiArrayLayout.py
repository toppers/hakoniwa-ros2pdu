
import struct
from .pdu_pytype_MultiArrayLayout import MultiArrayLayout
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_MultiArrayDimension import pdu_to_py_, py_to_pdu_


def pdu_to_py_MultiArrayLayout(pdu_bytes: bytes) -> MultiArrayLayout:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = MultiArrayLayout()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: dim (varray)
    
    ref_offset = 0
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.dim = []
    element_size = 136
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        nested_pdu_bytes = heap_data[current_heap_offset:]
        val = pdu_to_py_MultiArrayDimension(nested_pdu_bytes)
        py_obj.dim.append(val)
        # Move offset by the total size of the nested PDU
        _m, _b, nested_heap = unpack_pdu(nested_pdu_bytes)
        current_heap_offset += _m['total_size']
    
    
    
    # Processing: data_offset (single)
    
    
    py_obj.data_offset = struct.unpack_from('<I', base_data, 8)[0]
    
    
    
    return py_obj

def py_to_pdu_MultiArrayLayout(py_obj: MultiArrayLayout) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 12
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: dim (varray)
    
    array_len = len(py_obj.dim)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    # 構造体の可変長配列
    for element in py_obj.dim:
        nested_pdu_bytes = py_to_pdu_MultiArrayDimension(element)
        elements_heap_bytes += nested_pdu_bytes
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 0, array_len, heap_offset)
    
    
    # Processing: data_offset (single)
    
    
    struct.pack_into('<I', base_buffer, 8, py_obj.data_offset)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
