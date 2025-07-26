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