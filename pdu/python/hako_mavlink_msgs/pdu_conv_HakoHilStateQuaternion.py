
import struct
from .pdu_pytype_HakoHilStateQuaternion import HakoHilStateQuaternion
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class


def pdu_to_py_HakoHilStateQuaternion(pdu_bytes: bytes) -> HakoHilStateQuaternion:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = HakoHilStateQuaternion()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: time_usec (single)
    
    
    py_obj.time_usec = struct.unpack_from('<Q', base_data, 0)[0]
    
    
    
    # Processing: attitude_quaternion (array)
    
    py_obj.attitude_quaternion = []
    element_size = 4
    for i in range(4):
        element_offset = 8 + i * element_size
    
        val = struct.unpack_from('<f', base_data, element_offset)[0]
        py_obj.attitude_quaternion.append(val)
    
    
    
    # Processing: rollspeed (single)
    
    
    py_obj.rollspeed = struct.unpack_from('<f', base_data, 24)[0]
    
    
    
    # Processing: pitchspeed (single)
    
    
    py_obj.pitchspeed = struct.unpack_from('<f', base_data, 28)[0]
    
    
    
    # Processing: yawspeed (single)
    
    
    py_obj.yawspeed = struct.unpack_from('<f', base_data, 32)[0]
    
    
    
    # Processing: lat (single)
    
    
    py_obj.lat = struct.unpack_from('<i', base_data, 36)[0]
    
    
    
    # Processing: lon (single)
    
    
    py_obj.lon = struct.unpack_from('<i', base_data, 40)[0]
    
    
    
    # Processing: alt (single)
    
    
    py_obj.alt = struct.unpack_from('<i', base_data, 44)[0]
    
    
    
    # Processing: vx (single)
    
    
    py_obj.vx = struct.unpack_from('<h', base_data, 48)[0]
    
    
    
    # Processing: vy (single)
    
    
    py_obj.vy = struct.unpack_from('<h', base_data, 50)[0]
    
    
    
    # Processing: vz (single)
    
    
    py_obj.vz = struct.unpack_from('<h', base_data, 52)[0]
    
    
    
    # Processing: ind_airspeed (single)
    
    
    py_obj.ind_airspeed = struct.unpack_from('<H', base_data, 54)[0]
    
    
    
    # Processing: true_airspeed (single)
    
    
    py_obj.true_airspeed = struct.unpack_from('<H', base_data, 56)[0]
    
    
    
    # Processing: xacc (single)
    
    
    py_obj.xacc = struct.unpack_from('<h', base_data, 58)[0]
    
    
    
    # Processing: yacc (single)
    
    
    py_obj.yacc = struct.unpack_from('<h', base_data, 60)[0]
    
    
    
    # Processing: zacc (single)
    
    
    py_obj.zacc = struct.unpack_from('<h', base_data, 62)[0]
    
    
    
    return py_obj

def py_to_pdu_HakoHilStateQuaternion(py_obj: HakoHilStateQuaternion) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 64
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: time_usec (single)
    
    
    struct.pack_into('<Q', base_buffer, 0, py_obj.time_usec)
    
    
    
    # Processing: attitude_quaternion (array)
    
    element_size = 4
    for i, element in enumerate(py_obj.attitude_quaternion):
        if i >= 4: break
        element_offset = 8 + i * element_size
    
        struct.pack_into('<f', base_buffer, element_offset, element)
    
    
    
    # Processing: rollspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 24, py_obj.rollspeed)
    
    
    
    # Processing: pitchspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 28, py_obj.pitchspeed)
    
    
    
    # Processing: yawspeed (single)
    
    
    struct.pack_into('<f', base_buffer, 32, py_obj.yawspeed)
    
    
    
    # Processing: lat (single)
    
    
    struct.pack_into('<i', base_buffer, 36, py_obj.lat)
    
    
    
    # Processing: lon (single)
    
    
    struct.pack_into('<i', base_buffer, 40, py_obj.lon)
    
    
    
    # Processing: alt (single)
    
    
    struct.pack_into('<i', base_buffer, 44, py_obj.alt)
    
    
    
    # Processing: vx (single)
    
    
    struct.pack_into('<h', base_buffer, 48, py_obj.vx)
    
    
    
    # Processing: vy (single)
    
    
    struct.pack_into('<h', base_buffer, 50, py_obj.vy)
    
    
    
    # Processing: vz (single)
    
    
    struct.pack_into('<h', base_buffer, 52, py_obj.vz)
    
    
    
    # Processing: ind_airspeed (single)
    
    
    struct.pack_into('<H', base_buffer, 54, py_obj.ind_airspeed)
    
    
    
    # Processing: true_airspeed (single)
    
    
    struct.pack_into('<H', base_buffer, 56, py_obj.true_airspeed)
    
    
    
    # Processing: xacc (single)
    
    
    struct.pack_into('<h', base_buffer, 58, py_obj.xacc)
    
    
    
    # Processing: yacc (single)
    
    
    struct.pack_into('<h', base_buffer, 60, py_obj.yacc)
    
    
    
    # Processing: zacc (single)
    
    
    struct.pack_into('<h', base_buffer, 62, py_obj.zacc)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
