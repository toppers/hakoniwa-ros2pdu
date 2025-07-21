
import struct
from .pdu_pytype_TFMessage import TFMessage
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..geometry_msgs.pdu_conv_TransformStamped import pdu_to_py_TransformStamped, py_to_pdu_TransformStamped


def pdu_to_py_TFMessage(pdu_bytes: bytes) -> TFMessage:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = TFMessage()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: transforms (varray)
    
    ref_offset = 0
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.transforms = []
    element_size = 320
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        nested_pdu_bytes = heap_data[current_heap_offset:]
        val = pdu_to_py_TransformStamped(nested_pdu_bytes)
        py_obj.transforms.append(val)
        # Move offset by the total size of the nested PDU
        _m, _b, nested_heap = unpack_pdu(nested_pdu_bytes)
        current_heap_offset += _m['total_size']
    
    
    
    return py_obj

def py_to_pdu_TFMessage(py_obj: TFMessage) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 320
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: transforms (varray)
    
    array_len = len(py_obj.transforms)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    # 構造体の可変長配列
    for element in py_obj.transforms:
        nested_pdu_bytes = py_to_pdu_TransformStamped(element)
        elements_heap_bytes += nested_pdu_bytes
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 0, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
