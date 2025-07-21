
import struct
from .pdu_pytype_Ev3PduSensor import Ev3PduSensor
from ..pdu_utils import PduDynamicMemoryPython, create_pdu, unpack_pdu, _VARRAY_REF_FORMAT, _VARRAY_REF_SIZE

# dependencies for the generated Python class

from ..ev3_msgs.pdu_conv_Ev3PduSensorHeader import pdu_to_py_, py_to_pdu_

from ..ev3_msgs.pdu_conv_Ev3PduColorSensor import pdu_to_py_, py_to_pdu_

from ..ev3_msgs.pdu_conv_Ev3PduTouchSensor import pdu_to_py_, py_to_pdu_


def pdu_to_py_Ev3PduSensor(pdu_bytes: bytes) -> Ev3PduSensor:
    """PDUバイト列からPythonオブジェクトを生成（デシリアライズ）"""
    metadata, base_data, heap_data = unpack_pdu(pdu_bytes)
    
    py_obj = Ev3PduSensor()

    # 各フィールドをオフセット情報に基づいてデコード
    
    # Processing: head (single)
    
    
    nested_base_data = base_data[0:152]
    nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
    py_obj.head = pdu_to_py_Ev3PduSensorHeader(nested_pdu_bytes)
    
    
    
    # Processing: buttons (array)
    
    py_obj.buttons = []
    element_size = 1
    for i in range(1):
        element_offset = 152 + i * element_size
    
        val = struct.unpack_from('<B', base_data, element_offset)[0]
        py_obj.buttons.append(val)
    
    
    
    # Processing: color_sensors (array)
    
    py_obj.color_sensors = []
    element_size = 20
    for i in range(2):
        element_offset = 156 + i * element_size
    
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_Ev3PduColorSensor(nested_pdu_bytes)
        py_obj.color_sensors.append(val)
    
    
    
    # Processing: touch_sensors (array)
    
    py_obj.touch_sensors = []
    element_size = 4
    for i in range(2):
        element_offset = 196 + i * element_size
    
        nested_base_data = base_data[element_offset : element_offset + element_size]
        nested_pdu_bytes = create_pdu(nested_base_data, heap_data)
        val = pdu_to_py_Ev3PduTouchSensor(nested_pdu_bytes)
        py_obj.touch_sensors.append(val)
    
    
    
    # Processing: motor_angle (array)
    
    py_obj.motor_angle = []
    element_size = 4
    for i in range(3):
        element_offset = 204 + i * element_size
    
        val = struct.unpack_from('<I', base_data, element_offset)[0]
        py_obj.motor_angle.append(val)
    
    
    
    # Processing: gyro_degree (single)
    
    
    py_obj.gyro_degree = struct.unpack_from('<i', base_data, 216)[0]
    
    
    
    # Processing: gyro_degree_rate (single)
    
    
    py_obj.gyro_degree_rate = struct.unpack_from('<i', base_data, 220)[0]
    
    
    
    # Processing: sensor_ultrasonic (single)
    
    
    py_obj.sensor_ultrasonic = struct.unpack_from('<I', base_data, 224)[0]
    
    
    
    # Processing: gps_lat (single)
    
    
    py_obj.gps_lat = struct.unpack_from('<d', base_data, 232)[0]
    
    
    
    # Processing: gps_lon (single)
    
    
    py_obj.gps_lon = struct.unpack_from('<d', base_data, 240)[0]
    
    
    
    return py_obj

def py_to_pdu_Ev3PduSensor(py_obj: Ev3PduSensor) -> bytes:
    """PythonオブジェクトからPDUバイト列を生成（シリアライズ）"""
    base_data_size = 248
    base_buffer = bytearray(base_data_size)
    heap = PduDynamicMemoryPython()

    
    # Processing: head (single)
    
    
    nested_pdu_bytes = py_to_pdu_Ev3PduSensorHeader(py_obj.head)
    _m, nested_base_data, nested_heap_data = unpack_pdu(nested_pdu_bytes)
    base_buffer[0:152] = nested_base_data
    if nested_heap_data:
        heap.allocate(nested_heap_data) # Note: This is a simplified merge
    
    
    
    # Processing: buttons (array)
    
    element_size = 1
    for i, element in enumerate(py_obj.buttons):
        if i >= 1: break
        element_offset = 152 + i * element_size
    
        struct.pack_into('<B', base_buffer, element_offset, element)
    
    
    
    # Processing: color_sensors (array)
    
    element_size = 20
    for i, element in enumerate(py_obj.color_sensors):
        if i >= 2: break
        element_offset = 156 + i * element_size
    
        nested_pdu_bytes = py_to_pdu_Ev3PduColorSensor(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    
    
    
    # Processing: touch_sensors (array)
    
    element_size = 4
    for i, element in enumerate(py_obj.touch_sensors):
        if i >= 2: break
        element_offset = 196 + i * element_size
    
        nested_pdu_bytes = py_to_pdu_Ev3PduTouchSensor(element)
        _m, nested_base_data, _nhd = unpack_pdu(nested_pdu_bytes)
        base_buffer[element_offset : element_offset + element_size] = nested_base_data
    
    
    
    # Processing: motor_angle (array)
    
    element_size = 4
    for i, element in enumerate(py_obj.motor_angle):
        if i >= 3: break
        element_offset = 204 + i * element_size
    
        struct.pack_into('<I', base_buffer, element_offset, element)
    
    
    
    # Processing: gyro_degree (single)
    
    
    struct.pack_into('<i', base_buffer, 216, py_obj.gyro_degree)
    
    
    
    # Processing: gyro_degree_rate (single)
    
    
    struct.pack_into('<i', base_buffer, 220, py_obj.gyro_degree_rate)
    
    
    
    # Processing: sensor_ultrasonic (single)
    
    
    struct.pack_into('<I', base_buffer, 224, py_obj.sensor_ultrasonic)
    
    
    
    # Processing: gps_lat (single)
    
    
    struct.pack_into('<d', base_buffer, 232, py_obj.gps_lat)
    
    
    
    # Processing: gps_lon (single)
    
    
    struct.pack_into('<d', base_buffer, 240, py_obj.gps_lon)
    
    
    

    return create_pdu(bytes(base_buffer), heap.get_bytes())
