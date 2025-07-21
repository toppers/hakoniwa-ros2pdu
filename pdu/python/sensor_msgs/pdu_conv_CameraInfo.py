
import struct
from .pdu_pytype_CameraInfo import CameraInfo
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..std_msgs.pdu_conv_Header import pdu_to_py_, py_to_pdu_

from ..sensor_msgs.pdu_conv_RegionOfInterest import pdu_to_py_, py_to_pdu_


def pdu_to_py_CameraInfo(pdu_bytes: bytes) -> CameraInfo:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = CameraInfo()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: header (single)
    
    
    nested_base_data = base_data[0:136]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.header = pdu_to_py_Header(nested_pdu_bytes)
    
    
    
    # Processing: height (single)
    
    
    py_obj.height = struct.unpack_from('<I', base_data, 136)[0]
    
    
    
    # Processing: width (single)
    
    
    py_obj.width = struct.unpack_from('<I', base_data, 140)[0]
    
    
    
    # Processing: distortion_model (single)
    
    
    py_obj.distortion_model = struct.unpack_from('<', base_data, 144)[0]
    
    
    
    # Processing: d (varray)
    
    ref_offset = 272
    array_len, heap_offset = struct.unpack_from(_VARRAY_REF_FORMAT, base_data, ref_offset)
    py_obj.d = []
    element_size = 8
    current_heap_offset = heap_offset
    for i in range(array_len):
    
        val = struct.unpack_from('<d', heap_data, current_heap_offset)[0]
        py_obj.d.append(val)
        current_heap_offset += element_size
    
    
    
    # Processing: k (array)
    
    py_obj.k = []
    element_size = 8
    for i in range(9):
        element_offset = 280 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.k.append(val)
    
    
    
    # Processing: r (array)
    
    py_obj.r = []
    element_size = 8
    for i in range(9):
        element_offset = 352 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.r.append(val)
    
    
    
    # Processing: p (array)
    
    py_obj.p = []
    element_size = 8
    for i in range(12):
        element_offset = 424 + i * element_size
    
        val = struct.unpack_from('<d', base_data, element_offset)[0]
        py_obj.p.append(val)
    
    
    
    # Processing: binning_x (single)
    
    
    py_obj.binning_x = struct.unpack_from('<I', base_data, 520)[0]
    
    
    
    # Processing: binning_y (single)
    
    
    py_obj.binning_y = struct.unpack_from('<I', base_data, 524)[0]
    
    
    
    # Processing: roi (single)
    
    
    nested_base_data = base_data[528:548]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.roi = pdu_to_py_RegionOfInterest(nested_pdu_bytes)
    
    
    
    return py_obj

def py_to_pdu_CameraInfo(py_obj: CameraInfo) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 548
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
    
    
    
    # Processing: distortion_model (single)
    
    
    struct.pack_into('<', base_buffer, 144, py_obj.distortion_model)
    
    
    
    # Processing: d (varray)
    
    array_len = len(py_obj.d)
    
    # 可変長配列の実データを先にヒープに確保
    elements_heap_bytes = bytearray()
    
    for element in py_obj.d:
        elements_heap_bytes += struct.pack('<d', element)
    heap_offset = heap.allocate(bytes(elements_heap_bytes))
    

    # BaseDataに参照情報を書き込む
    struct.pack_into(_VARRAY_REF_FORMAT, base_buffer, 272, array_len, heap_offset)
    
    
    # Processing: k (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.k):
        if i >= 9: break
        element_offset = 280 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: r (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.r):
        if i >= 9: break
        element_offset = 352 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: p (array)
    
    element_size = 8
    for i, element in enumerate(py_obj.p):
        if i >= 12: break
        element_offset = 424 + i * element_size
    
        struct.pack_into('<d', base_buffer, element_offset, element)
    
    
    
    # Processing: binning_x (single)
    
    
    struct.pack_into('<I', base_buffer, 520, py_obj.binning_x)
    
    
    
    # Processing: binning_y (single)
    
    
    struct.pack_into('<I', base_buffer, 524, py_obj.binning_y)
    
    
    
    # Processing: roi (single)
    
    
    nested_pdu_bytes = py_to_pdu_RegionOfInterest(py_obj.roi)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[528:548] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
