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


if __name__ == "__main__":
    unittest.main()
