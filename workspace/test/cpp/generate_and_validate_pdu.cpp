#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>
#include <string>

#include "pdu/types/tf2_msgs/pdu_cpptype_conv_TFMessage.hpp"
#include "pdu/types/geometry_msgs/pdu_cpptype_conv_TransformStamped.hpp"
#include "pdu/types/geometry_msgs/pdu_cpptype_conv_Point.hpp"
#include "pdu/types/sensor_msgs/pdu_cpptype_conv_Imu.hpp"
#include "pdu/types/geometry_msgs/pdu_cpptype_conv_Twist.hpp"
#include "pdu/types/hako_msgs/pdu_cpptype_conv_HakoCameraData.hpp"
#include "pdu/types/sensor_msgs/pdu_cpptype_conv_PointCloud2.hpp"
#include "pdu/types/ev3_msgs/pdu_cpptype_conv_Ev3PduSensor.hpp"
#include "pdu/types/ev3_msgs/pdu_cpptype_conv_Ev3PduSensorHeader.hpp"
#include "pdu/types/ev3_msgs/pdu_cpptype_conv_Ev3PduColorSensor.hpp"
#include "pdu/types/ev3_msgs/pdu_cpptype_conv_Ev3PduTouchSensor.hpp"

void validate_tf_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_TFMessage cpp_msg;
    hako::pdu::msgs::tf2_msgs::TFMessage conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating TFMessage from Python..." << std::endl;
    assert(cpp_msg.transforms.size() == 1);
    assert(cpp_msg.transforms[0].header.frame_id == "world");
    assert(abs(cpp_msg.transforms[0].transform.translation.x - 1.0) < 1e-6);
    std::cout << "SUCCESS: Validation of TFMessage from Python passed." << std::endl;
}

void generate_tf_message(const std::string& pdu_file_prefix) {
    HakoCpp_TFMessage cpp_msg;
    HakoCpp_TransformStamped transform;
    transform.header.stamp.sec = 123;
    transform.header.stamp.nanosec = 456;
    transform.header.frame_id = "world";
    transform.child_frame_id = "base_link";
    transform.transform.translation.x = 1.0;
    transform.transform.translation.y = 2.0;
    transform.transform.translation.z = 3.0;
    transform.transform.rotation.x = 0.0;
    transform.transform.rotation.y = 0.0;
    transform.transform.rotation.z = 0.0;
    transform.transform.rotation.w = 1.0;
    cpp_msg.transforms.push_back(transform);

    Hako_TFMessage* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_TFMessage(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_point_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_Point cpp_msg;
    hako::pdu::msgs::geometry_msgs::Point conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating Point from Python..." << std::endl;
    assert(abs(cpp_msg.x - 1.1) < 1e-6);
    assert(abs(cpp_msg.y - 2.2) < 1e-6);
    assert(abs(cpp_msg.z - 3.3) < 1e-6);
    std::cout << "SUCCESS: Validation of Point from Python passed." << std::endl;
}

void generate_point_message(const std::string& pdu_file_prefix) {
    HakoCpp_Point cpp_msg;
    cpp_msg.x = 1.1;
    cpp_msg.y = 2.2;
    cpp_msg.z = 3.3;

    Hako_Point* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_Point(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_imu_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_Imu cpp_msg;
    hako::pdu::msgs::sensor_msgs::Imu conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating Imu from Python..." << std::endl;
    assert(abs(cpp_msg.orientation.x - 0.1) < 1e-6);
    assert(abs(cpp_msg.orientation.y - 0.2) < 1e-6);
    assert(abs(cpp_msg.orientation.z - 0.3) < 1e-6);
    assert(abs(cpp_msg.orientation.w - 0.4) < 1e-6);
    std::cout << "SUCCESS: Validation of Imu from Python passed." << std::endl;
}

void generate_imu_message(const std::string& pdu_file_prefix) {
    HakoCpp_Imu cpp_msg;
    cpp_msg.orientation.x = 0.1;
    cpp_msg.orientation.y = 0.2;
    cpp_msg.orientation.z = 0.3;
    cpp_msg.orientation.w = 0.4;

    Hako_Imu* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_Imu(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_twist_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_Twist cpp_msg;
    hako::pdu::msgs::geometry_msgs::Twist conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating Twist from Python..." << std::endl;
    assert(abs(cpp_msg.linear.x - 10.0) < 1e-6);
    assert(abs(cpp_msg.linear.y - 20.0) < 1e-6);
    assert(abs(cpp_msg.linear.z - 30.0) < 1e-6);
    assert(abs(cpp_msg.angular.x - 0.1) < 1e-6);
    assert(abs(cpp_msg.angular.y - 0.2) < 1e-6);
    assert(abs(cpp_msg.angular.z - 0.3) < 1e-6);
    std::cout << "SUCCESS: Validation of Twist from Python passed." << std::endl;
}

void generate_twist_message(const std::string& pdu_file_prefix) {
    HakoCpp_Twist cpp_msg;
    cpp_msg.linear.x = 10.0;
    cpp_msg.linear.y = 20.0;
    cpp_msg.linear.z = 30.0;
    cpp_msg.angular.x = 0.1;
    cpp_msg.angular.y = 0.2;
    cpp_msg.angular.z = 0.3;

    Hako_Twist* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_Twist(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_hako_camera_data_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_HakoCameraData cpp_msg;
    hako::pdu::msgs::hako_msgs::HakoCameraData conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating HakoCameraData from Python..." << std::endl;
    assert(cpp_msg.request_id == 12345);
    assert(cpp_msg.image.header.stamp.sec == 100);
    assert(cpp_msg.image.header.stamp.nanosec == 200);
    assert(cpp_msg.image.header.frame_id == "camera_frame");
    assert(cpp_msg.image.format == "jpeg");
    assert(cpp_msg.image.data.size() == 10);
    for (size_t i = 0; i < cpp_msg.image.data.size(); ++i) {
        assert(cpp_msg.image.data[i] == (char)(i + 1));
    }
    std::cout << "SUCCESS: Validation of HakoCameraData from Python passed." << std::endl;
}

void generate_hako_camera_data_message(const std::string& pdu_file_prefix) {
    HakoCpp_HakoCameraData cpp_msg;
    cpp_msg.request_id = 12345;
    cpp_msg.image.header.stamp.sec = 100;
    cpp_msg.image.header.stamp.nanosec = 200;
    cpp_msg.image.header.frame_id = "camera_frame";
    cpp_msg.image.format = "jpeg";
    for (int i = 0; i < 10; ++i) {
        cpp_msg.image.data.push_back((char)(i + 1));
    }

    Hako_HakoCameraData* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_HakoCameraData(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_point_cloud_2_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_PointCloud2 cpp_msg;
    hako::pdu::msgs::sensor_msgs::PointCloud2 conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating PointCloud2 from Python..." << std::endl;
    assert(cpp_msg.header.stamp.sec == 1000);
    assert(cpp_msg.header.stamp.nanosec == 2000);
    assert(cpp_msg.header.frame_id == "cloud_frame");
    assert(cpp_msg.height == 1);
    assert(cpp_msg.width == 10);
    assert(cpp_msg.fields.size() == 2);
    assert(cpp_msg.fields[0].name == "x");
    assert(cpp_msg.fields[0].offset == 0);
    assert(cpp_msg.fields[0].datatype == 7);
    assert(cpp_msg.fields[0].count == 1);
    assert(cpp_msg.fields[1].name == "y");
    assert(cpp_msg.fields[1].offset == 4);
    assert(cpp_msg.fields[1].datatype == 7);
    assert(cpp_msg.fields[1].count == 1);
    assert(cpp_msg.is_bigendian == false);
    assert(cpp_msg.point_step == 8);
    assert(cpp_msg.row_step == 80);
    assert(cpp_msg.data.size() == 10);
    for (size_t i = 0; i < cpp_msg.data.size(); ++i) {
        assert(cpp_msg.data[i] == (char)(i + 1));
    }
    assert(cpp_msg.is_dense == true);
    std::cout << "SUCCESS: Validation of PointCloud2 from Python passed." << std::endl;
}

void validate_ev3_pdu_sensor_message(const std::string& pdu_file_prefix) {
    std::string filename = pdu_file_prefix + "_from_py.pdu";
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open " << filename << std::endl;
        exit(1);
    }
    std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    HakoCpp_Ev3PduSensor cpp_msg;
    hako::pdu::msgs::ev3_msgs::Ev3PduSensor conv;
    bool ret = conv.pdu2cpp(buffer.data(), cpp_msg);
    assert(ret);

    std::cout << "Validating EV3PduSensor from Python..." << std::endl;
    assert(cpp_msg.head.name == "sensor_test");
    assert(cpp_msg.head.version == 1);
    assert(cpp_msg.head.hakoniwa_time == 1234567890);
    assert(cpp_msg.head.ext_off == 0);
    assert(cpp_msg.head.ext_size == 0);
    assert(cpp_msg.buttons.size() == 1);
    assert(cpp_msg.buttons[0] == 1);
    assert(cpp_msg.color_sensors.size() == 2);
    assert(cpp_msg.color_sensors[0].color == 1);
    assert(cpp_msg.color_sensors[0].reflect == 10);
    assert(cpp_msg.color_sensors[0].rgb_r == 20);
    assert(cpp_msg.color_sensors[0].rgb_g == 30);
    assert(cpp_msg.color_sensors[0].rgb_b == 40);
    assert(cpp_msg.color_sensors[1].color == 2);
    assert(cpp_msg.color_sensors[1].reflect == 11);
    assert(cpp_msg.color_sensors[1].rgb_r == 21);
    assert(cpp_msg.color_sensors[1].rgb_g == 31);
    assert(cpp_msg.color_sensors[1].rgb_b == 41);
    assert(cpp_msg.touch_sensors.size() == 2);
    assert(cpp_msg.touch_sensors[0].value == 1);
    assert(cpp_msg.touch_sensors[1].value == 0);
    assert(cpp_msg.motor_angle.size() == 3);
    assert(cpp_msg.motor_angle[0] == 100);
    assert(cpp_msg.motor_angle[1] == 200);
    assert(cpp_msg.motor_angle[2] == 300);
    assert(cpp_msg.gyro_degree == 45);
    assert(cpp_msg.gyro_degree_rate == 5);
    assert(cpp_msg.sensor_ultrasonic == 250);
    assert(abs(cpp_msg.gps_lat - 35.681236) < 1e-6);
    assert(abs(cpp_msg.gps_lon - 139.767125) < 1e-6);
    std::cout << "SUCCESS: Validation of EV3PduSensor from Python passed." << std::endl;
}

void generate_ev3_pdu_sensor_message(const std::string& pdu_file_prefix) {
    HakoCpp_Ev3PduSensor cpp_msg;
    cpp_msg.head.name = "sensor_test";
    cpp_msg.head.version = 1;
    cpp_msg.head.hakoniwa_time = 1234567890;
    cpp_msg.head.ext_off = 0;
    cpp_msg.head.ext_size = 0;
    cpp_msg.buttons[0] = 1;

    HakoCpp_Ev3PduColorSensor color_sensor1;
    color_sensor1.color = 1;
    color_sensor1.reflect = 10;
    color_sensor1.rgb_r = 20;
    color_sensor1.rgb_g = 30;
    color_sensor1.rgb_b = 40;
    cpp_msg.color_sensors[0] = color_sensor1;

    HakoCpp_Ev3PduColorSensor color_sensor2;
    color_sensor2.color = 2;
    color_sensor2.reflect = 11;
    color_sensor2.rgb_r = 21;
    color_sensor2.rgb_g = 31;
    color_sensor2.rgb_b = 41;
    cpp_msg.color_sensors[1] = color_sensor2;

    HakoCpp_Ev3PduTouchSensor touch_sensor1;
    touch_sensor1.value = 1;
    cpp_msg.touch_sensors[0] = touch_sensor1;

    HakoCpp_Ev3PduTouchSensor touch_sensor2;
    touch_sensor2.value = 0;
    cpp_msg.touch_sensors[1] = touch_sensor2;

    cpp_msg.motor_angle[0] = 100;
    cpp_msg.motor_angle[1] = 200;
    cpp_msg.motor_angle[2] = 300;
    cpp_msg.gyro_degree = 45;
    cpp_msg.gyro_degree_rate = 5;
    cpp_msg.sensor_ultrasonic = 250;
    cpp_msg.gps_lat = 35.681236;
    cpp_msg.gps_lon = 139.767125;

    Hako_Ev3PduSensor* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_Ev3PduSensor(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void generate_point_cloud_2_message(const std::string& pdu_file_prefix) {
    HakoCpp_PointCloud2 cpp_msg;
    cpp_msg.header.stamp.sec = 1000;
    cpp_msg.header.stamp.nanosec = 2000;
    cpp_msg.header.frame_id = "cloud_frame";
    cpp_msg.height = 1;
    cpp_msg.width = 10;
    
    HakoCpp_PointField field1;
    field1.name = "x";
    field1.offset = 0;
    field1.datatype = 7;
    field1.count = 1;
    cpp_msg.fields.push_back(field1);

    HakoCpp_PointField field2;
    field2.name = "y";
    field2.offset = 4;
    field2.datatype = 7;
    field2.count = 1;
    cpp_msg.fields.push_back(field2);

    cpp_msg.is_bigendian = false;
    cpp_msg.point_step = 8;
    cpp_msg.row_step = 80;
    for (int i = 0; i < 10; ++i) {
        cpp_msg.data.push_back((char)(i + 1));
    }
    cpp_msg.is_dense = true;

    Hako_PointCloud2* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_PointCloud2(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::string filename = pdu_file_prefix + "_from_cpp.pdu";
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated " << filename << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

// Function pointer type for test functions
typedef void (*TestFunction)(const std::string&);

// Test function table
struct TestEntry {
    std::string name;
    TestFunction generate_func;
    TestFunction validate_func;
};

TestEntry test_table[] = {
    { "tf_message", generate_tf_message, validate_tf_message },
    { "point", generate_point_message, validate_point_message },
    { "imu", generate_imu_message, validate_imu_message },
    { "twist", generate_twist_message, validate_twist_message },
    { "hako_camera_data", generate_hako_camera_data_message, validate_hako_camera_data_message },
    { "point_cloud_2", generate_point_cloud_2_message, validate_point_cloud_2_message },
    { "ev3_pdu_sensor", generate_ev3_pdu_sensor_message, validate_ev3_pdu_sensor_message },
    // Add new test functions here
    { "", nullptr, nullptr } // Sentinel
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [generate|validate] [target] [pdu_file_prefix]" << std::endl;
        return 1;
    }
    std::string mode = argv[1];
    std::string target = argv[2];
    std::string pdu_file_prefix = argv[3];

    bool found_target = false;
    for (int i = 0; test_table[i].name != ""; ++i) {
        if (target == "all" || target == test_table[i].name) {
            found_target = true;
            if (mode == "generate") {
                if (test_table[i].generate_func) {
                    test_table[i].generate_func(pdu_file_prefix);
                }
            } else if (mode == "validate") {
                if (test_table[i].validate_func) {
                    test_table[i].validate_func(pdu_file_prefix);
                }
            } else {
                std::cerr << "Invalid mode: " << mode << std::endl;
                return 1;
            }
        }
    }

    if (!found_target) {
        std::cerr << "Invalid target: " << target << std::endl;
        return 1;
    }

    return 0;
}