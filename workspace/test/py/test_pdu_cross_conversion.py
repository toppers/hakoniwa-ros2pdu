import sys
import os
import unittest

sys.path.append(os.path.join(os.path.dirname(__file__), '../../..'))

from pdu.python.tf2_msgs.pdu_conv_TFMessage import pdu_to_py_TFMessage, py_to_pdu_TFMessage
from pdu.python.tf2_msgs.pdu_pytype_TFMessage import TFMessage
from pdu.python.geometry_msgs.pdu_pytype_TransformStamped import TransformStamped
from pdu.python.std_msgs.pdu_pytype_Header import Header
from pdu.python.builtin_interfaces.pdu_pytype_Time import Time
from pdu.python.geometry_msgs.pdu_pytype_Transform import Transform
from pdu.python.geometry_msgs.pdu_pytype_Vector3 import Vector3
from pdu.python.geometry_msgs.pdu_pytype_Quaternion import Quaternion
from pdu.python.geometry_msgs.pdu_conv_Point import pdu_to_py_Point, py_to_pdu_Point
from pdu.python.geometry_msgs.pdu_pytype_Point import Point
from pdu.python.sensor_msgs.pdu_conv_Imu import pdu_to_py_Imu, py_to_pdu_Imu
from pdu.python.sensor_msgs.pdu_pytype_Imu import Imu
from pdu.python.geometry_msgs.pdu_conv_Twist import pdu_to_py_Twist, py_to_pdu_Twist
from pdu.python.geometry_msgs.pdu_pytype_Twist import Twist
from pdu.python.hako_msgs.pdu_conv_HakoCameraData import pdu_to_py_HakoCameraData, py_to_pdu_HakoCameraData
from pdu.python.hako_msgs.pdu_pytype_HakoCameraData import HakoCameraData
from pdu.python.sensor_msgs.pdu_conv_PointCloud2 import pdu_to_py_PointCloud2, py_to_pdu_PointCloud2
from pdu.python.sensor_msgs.pdu_pytype_PointCloud2 import PointCloud2
from pdu.python.sensor_msgs.pdu_pytype_PointField import PointField
from pdu.python.sensor_msgs.pdu_pytype_CompressedImage import CompressedImage
from pdu.python.std_msgs.pdu_pytype_Header import Header
from pdu.python.builtin_interfaces.pdu_pytype_Time import Time
from pdu.python.ev3_msgs.pdu_conv_Ev3PduSensor import pdu_to_py_Ev3PduSensor, py_to_pdu_Ev3PduSensor
from pdu.python.ev3_msgs.pdu_pytype_Ev3PduSensor import Ev3PduSensor
from pdu.python.ev3_msgs.pdu_pytype_Ev3PduSensorHeader import Ev3PduSensorHeader
from pdu.python.ev3_msgs.pdu_pytype_Ev3PduColorSensor import Ev3PduColorSensor
from pdu.python.ev3_msgs.pdu_pytype_Ev3PduTouchSensor import Ev3PduTouchSensor

class TestPduCrossConversion(unittest.TestCase):

    def setUp(self):
        self.pdu_file_prefix = os.getenv("PDU_FILE_PREFIX")

    def test_serialize_tf_message_from_python(self):
        print("\n--- Running test_serialize_tf_message_from_python ---")
        py_msg = TFMessage()
        transform = TransformStamped()
        transform.header.stamp.sec = 123
        transform.header.frame_id = "world"
        transform.child_frame_id = "base_link"
        transform.transform.translation.x = 1.0
        py_msg.transforms.append(transform)

        pdu_bytes = py_to_pdu_TFMessage(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_tf_message_from_cpp(self):
        print("\n--- Running test_deserialize_tf_message_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_TFMessage(pdu_bytes)
        
        self.assertIsInstance(py_msg, TFMessage)
        self.assertEqual(len(py_msg.transforms), 1)
        self.assertEqual(py_msg.transforms[0].header.frame_id, "world")
        self.assertAlmostEqual(py_msg.transforms[0].transform.translation.x, 1.0, places=6)
        print("SUCCESS: Deserialization of TFMessage from C++ passed.")

    def test_serialize_point_from_python(self):
        print("\n--- Running test_serialize_point_from_python ---")
        py_msg = Point()
        py_msg.x = 1.1
        py_msg.y = 2.2
        py_msg.z = 3.3
        
        pdu_bytes = py_to_pdu_Point(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_point_from_cpp(self):
        print("\n--- Running test_deserialize_point_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_Point(pdu_bytes)
        
        self.assertIsInstance(py_msg, Point)
        self.assertAlmostEqual(py_msg.x, 1.1, places=6)
        self.assertAlmostEqual(py_msg.y, 2.2, places=6)
        self.assertAlmostEqual(py_msg.z, 3.3, places=6)
        print("SUCCESS: Deserialization of Point from C++ passed.")

    def test_serialize_imu_from_python(self):
        print("\n--- Running test_serialize_imu_from_python ---")
        py_msg = Imu()
        py_msg.orientation.x = 0.1
        py_msg.orientation.y = 0.2
        py_msg.orientation.z = 0.3
        py_msg.orientation.w = 0.4
        
        pdu_bytes = py_to_pdu_Imu(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_imu_from_cpp(self):
        print("\n--- Running test_deserialize_imu_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_Imu(pdu_bytes)
        
        self.assertIsInstance(py_msg, Imu)
        self.assertAlmostEqual(py_msg.orientation.x, 0.1, places=6)
        self.assertAlmostEqual(py_msg.orientation.y, 0.2, places=6)
        self.assertAlmostEqual(py_msg.orientation.z, 0.3, places=6)
        self.assertAlmostEqual(py_msg.orientation.w, 0.4, places=6)
        print("SUCCESS: Deserialization of Imu from C++ passed.")

    def test_serialize_twist_from_python(self):
        print("\n--- Running test_serialize_twist_from_python ---")
        py_msg = Twist()
        py_msg.linear.x = 10.0
        py_msg.linear.y = 20.0
        py_msg.linear.z = 30.0
        py_msg.angular.x = 0.1
        py_msg.angular.y = 0.2
        py_msg.angular.z = 0.3
        
        pdu_bytes = py_to_pdu_Twist(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_twist_from_cpp(self):
        print("\n--- Running test_deserialize_twist_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_Twist(pdu_bytes)
        
        self.assertIsInstance(py_msg, Twist)
        self.assertAlmostEqual(py_msg.linear.x, 10.0, places=6)
        self.assertAlmostEqual(py_msg.linear.y, 20.0, places=6)
        self.assertAlmostEqual(py_msg.linear.z, 30.0, places=6)
        self.assertAlmostEqual(py_msg.angular.x, 0.1, places=6)
        self.assertAlmostEqual(py_msg.angular.y, 0.2, places=6)
        self.assertAlmostEqual(py_msg.angular.z, 0.3, places=6)
        print("SUCCESS: Deserialization of Twist from C++ passed.")

    def test_serialize_hako_camera_data_from_python(self):
        print("\n--- Running test_serialize_hako_camera_data_from_python ---")
        py_msg = HakoCameraData()
        py_msg.request_id = 12345
        py_msg.image.header.stamp.sec = 100
        py_msg.image.header.stamp.nanosec = 200
        py_msg.image.header.frame_id = "camera_frame"
        py_msg.image.format = "jpeg"
        py_msg.image.data = bytes([i + 1 for i in range(10)])
        
        pdu_bytes = py_to_pdu_HakoCameraData(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_hako_camera_data_from_cpp(self):
        print("\n--- Running test_deserialize_hako_camera_data_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_HakoCameraData(pdu_bytes)
        
        self.assertIsInstance(py_msg, HakoCameraData)
        self.assertEqual(py_msg.request_id, 12345)
        self.assertEqual(py_msg.image.header.stamp.sec, 100)
        self.assertEqual(py_msg.image.header.stamp.nanosec, 200)
        self.assertEqual(py_msg.image.header.frame_id, "camera_frame")
        self.assertEqual(py_msg.image.format, "jpeg")
        self.assertEqual(py_msg.image.data, bytes([i + 1 for i in range(10)]))
        print("SUCCESS: Deserialization of HakoCameraData from C++ passed.")

    def test_serialize_point_cloud_2_from_python(self):
        print("\n--- Running test_serialize_point_cloud_2_from_python ---")
        py_msg = PointCloud2()
        py_msg.header.stamp.sec = 1000
        py_msg.header.stamp.nanosec = 2000
        py_msg.header.frame_id = "cloud_frame"
        py_msg.height = 1
        py_msg.width = 10
        
        field1 = PointField()
        field1.name = "x"
        field1.offset = 0
        field1.datatype = 7
        field1.count = 1
        py_msg.fields.append(field1)

        field2 = PointField()
        field2.name = "y"
        field2.offset = 4
        field2.datatype = 7
        field2.count = 1
        py_msg.fields.append(field2)

        py_msg.is_bigendian = False
        py_msg.point_step = 8
        py_msg.row_step = 80
        py_msg.data = [i + 1 for i in range(10)]
        py_msg.is_dense = True
        
        pdu_bytes = py_to_pdu_PointCloud2(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_point_cloud_2_from_cpp(self):
        print("\n--- Running test_deserialize_point_cloud_2_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_PointCloud2(pdu_bytes)
        
        self.assertIsInstance(py_msg, PointCloud2)
        self.assertEqual(py_msg.header.stamp.sec, 1000)
        self.assertEqual(py_msg.header.stamp.nanosec, 2000)
        self.assertEqual(py_msg.header.frame_id, "cloud_frame")
        self.assertEqual(py_msg.height, 1)
        self.assertEqual(py_msg.width, 10)
        self.assertEqual(len(py_msg.fields), 2)
        self.assertEqual(py_msg.fields[0].name, "x")
        self.assertEqual(py_msg.fields[0].offset, 0)
        self.assertEqual(py_msg.fields[0].datatype, 7)
        self.assertEqual(py_msg.fields[0].count, 1)
        self.assertEqual(py_msg.fields[1].name, "y")
        self.assertEqual(py_msg.fields[1].offset, 4)
        self.assertEqual(py_msg.fields[1].datatype, 7)
        self.assertEqual(py_msg.fields[1].count, 1)
        self.assertEqual(py_msg.is_bigendian, False)
        self.assertEqual(py_msg.point_step, 8)
        self.assertEqual(py_msg.row_step, 80)
        self.assertEqual(list(py_msg.data), [i + 1 for i in range(10)])
        self.assertEqual(py_msg.is_dense, True)
        print("SUCCESS: Deserialization of PointCloud2 from C++ passed.")

    def test_serialize_ev3_pdu_sensor_from_python(self):
        print("\n--- Running test_serialize_ev3_pdu_sensor_from_python ---")
        py_msg = Ev3PduSensor()
        py_msg.head.name = "sensor_test"
        py_msg.head.version = 1
        py_msg.head.hakoniwa_time = 1234567890
        py_msg.head.ext_off = 0
        py_msg.head.ext_size = 0
        py_msg.buttons = bytes([1])

        color_sensor1 = Ev3PduColorSensor()
        color_sensor1.color = 1
        color_sensor1.reflect = 10
        color_sensor1.rgb_r = 20
        color_sensor1.rgb_g = 30
        color_sensor1.rgb_b = 40
        py_msg.color_sensors.append(color_sensor1)

        color_sensor2 = Ev3PduColorSensor()
        color_sensor2.color = 2
        color_sensor2.reflect = 11
        color_sensor2.rgb_r = 21
        color_sensor2.rgb_g = 31
        color_sensor2.rgb_b = 41
        py_msg.color_sensors.append(color_sensor2)

        touch_sensor1 = Ev3PduTouchSensor()
        touch_sensor1.value = 1
        py_msg.touch_sensors.append(touch_sensor1)

        touch_sensor2 = Ev3PduTouchSensor()
        touch_sensor2.value = 0
        py_msg.touch_sensors.append(touch_sensor2)

        py_msg.motor_angle = [100, 200, 300]
        py_msg.gyro_degree = 45
        py_msg.gyro_degree_rate = 5
        py_msg.sensor_ultrasonic = 250
        py_msg.gps_lat = 35.681236
        py_msg.gps_lon = 139.767125
        
        pdu_bytes = py_to_pdu_Ev3PduSensor(py_msg)
        
        filename = self.pdu_file_prefix + "_from_py.pdu"
        with open(filename, "wb") as f:
            f.write(pdu_bytes)
        print(f"SUCCESS: Generated {filename}")

    def test_deserialize_ev3_pdu_sensor_from_cpp(self):
        print("\n--- Running test_deserialize_ev3_pdu_sensor_from_cpp ---")
        pdu_file_path = self.pdu_file_prefix + '_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_Ev3PduSensor(pdu_bytes)
        
        self.assertIsInstance(py_msg, Ev3PduSensor)
        self.assertEqual(py_msg.head.name, "sensor_test")
        self.assertEqual(py_msg.head.version, 1)
        self.assertEqual(py_msg.head.hakoniwa_time, 1234567890)
        self.assertEqual(py_msg.head.ext_off, 0)
        self.assertEqual(py_msg.head.ext_size, 0)
        self.assertEqual(list(py_msg.buttons), [1])
        self.assertEqual(len(py_msg.color_sensors), 2)
        self.assertEqual(py_msg.color_sensors[0].color, 1)
        self.assertEqual(py_msg.color_sensors[0].reflect, 10)
        self.assertEqual(py_msg.color_sensors[0].rgb_r, 20)
        self.assertEqual(py_msg.color_sensors[0].rgb_g, 30)
        self.assertEqual(py_msg.color_sensors[0].rgb_b, 40)
        self.assertEqual(py_msg.color_sensors[1].color, 2)
        self.assertEqual(py_msg.color_sensors[1].reflect, 11)
        self.assertEqual(py_msg.color_sensors[1].rgb_r, 21)
        self.assertEqual(py_msg.color_sensors[1].rgb_g, 31)
        self.assertEqual(py_msg.color_sensors[1].rgb_b, 41)
        self.assertEqual(len(py_msg.touch_sensors), 2)
        self.assertEqual(py_msg.touch_sensors[0].value, 1)
        self.assertEqual(py_msg.touch_sensors[1].value, 0)
        self.assertEqual(list(py_msg.motor_angle), [100, 200, 300])
        self.assertEqual(py_msg.gyro_degree, 45)
        self.assertEqual(py_msg.gyro_degree_rate, 5)
        self.assertEqual(py_msg.sensor_ultrasonic, 250)
        self.assertAlmostEqual(py_msg.gps_lat, 35.681236, places=6)
        self.assertAlmostEqual(py_msg.gps_lon, 139.767125, places=6)
        print("SUCCESS: Deserialization of EV3PduSensor from C++ passed.")


if __name__ == "__main__":
    unittest.main()
