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

class TestPduCrossConversion(unittest.TestCase):

    def test_A_serialize_tf_message_from_python(self):
        print("\n--- Running test_A_serialize_tf_message_from_python ---")
        py_msg = TFMessage()
        transform = TransformStamped()
        transform.header.stamp.sec = 123
        transform.header.frame_id = "world"
        transform.child_frame_id = "base_link"
        transform.transform.translation.x = 1.0
        py_msg.transforms.append(transform)

        pdu_bytes = py_to_pdu_TFMessage(py_msg)
        
        with open("tf_from_py.pdu", "wb") as f:
            f.write(pdu_bytes)
        print("SUCCESS: Generated tf_from_py.pdu")

    def test_B_deserialize_tf_message_from_cpp(self):
        print("\n--- Running test_B_deserialize_tf_message_from_cpp ---")
        pdu_file_path = 'tf_from_cpp.pdu'
        self.assertTrue(os.path.exists(pdu_file_path), f"{pdu_file_path} not found. Run C++ test first.")

        with open(pdu_file_path, 'rb') as f:
            pdu_bytes = f.read()

        py_msg = pdu_to_py_TFMessage(pdu_bytes)
        
        self.assertIsInstance(py_msg, TFMessage)
        self.assertEqual(len(py_msg.transforms), 1)
        self.assertEqual(py_msg.transforms[0].header.frame_id, "world")
        self.assertAlmostEqual(py_msg.transforms[0].transform.translation.x, 1.0, places=6)
        print("SUCCESS: Deserialization of TFMessage from C++ passed.")

if __name__ == "__main__":
    unittest.main()
