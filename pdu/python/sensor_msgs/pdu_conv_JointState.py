
import struct
from .pdu_pytype_JointState import JointState
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_


def pdu_to_py_JointState(pdu_bytes: bytes) -> JointState:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = JointState()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: name (varray)
    
    ref_offset = 136
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.name = []
    element_size = 128
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<', heap_data, current_heap_offset)[0]
        py_obj.name.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: position (varray)
    
    ref_offset = 144
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.position = []
    element_size = 8
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<d', heap_data, current_heap_offset)[0]
        py_obj.position.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: velocity (varray)
    
    ref_offset = 152
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.velocity = []
    element_size = 8
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<d', heap_data, current_heap_offset)[0]
        py_obj.velocity.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: effort (varray)
    
    ref_offset = 160
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.effort = []
    element_size = 8
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<d', heap_data, current_heap_offset)[0]
        py_obj.effort.append(val)
        current_heap_offset += element_size
    
    
    
    return py_obj

def py_to_pdu_JointState(py_obj: JointState) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 168
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: header (single)
    
    
    nested_pdu_bytes = py_to_pdu_Header(py_obj.header)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:136] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: name (varray)
    
    array_len = len(py_obj.name)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.name:
        elements_heap_bytes += struct.pack('<', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 136, array_len, heap_offset)
    
    
    # Processing: position (varray)
    
    array_len = len(py_obj.position)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.position:
        elements_heap_bytes += struct.pack('<d', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 144, array_len, heap_offset)
    
    
    # Processing: velocity (varray)
    
    array_len = len(py_obj.velocity)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.velocity:
        elements_heap_bytes += struct.pack('<d', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 152, array_len, heap_offset)
    
    
    # Processing: effort (varray)
    
    array_len = len(py_obj.effort)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.effort:
        elements_heap_bytes += struct.pack('<d', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 160, array_len, heap_offset)
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
