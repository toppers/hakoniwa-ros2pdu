#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

#include "pdu/types/tf2_msgs/pdu_cpptype_conv_TFMessage.hpp"
#include "pdu/types/geometry_msgs/pdu_cpptype_conv_TransformStamped.hpp"
#include "pdu/types/geometry_msgs/pdu_cpptype_conv_Point.hpp"

void validate_tf_message() {
    std::ifstream ifs("tf_from_py.pdu", std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open tf_from_py.pdu" << std::endl;
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

void generate_tf_message() {
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

    std::ofstream ofs("tf_from_cpp.pdu", std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated tf_from_cpp.pdu" << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

void validate_point_message() {
    std::ifstream ifs("point_from_py.pdu", std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Can not open point_from_py.pdu" << std::endl;
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

void generate_point_message() {
    HakoCpp_Point cpp_msg;
    cpp_msg.x = 1.1;
    cpp_msg.y = 2.2;
    cpp_msg.z = 3.3;

    Hako_Point* pdu_ptr = nullptr;
    int pdu_size = hako_convert_cpp2pdu_Point(cpp_msg, &pdu_ptr);
    assert(pdu_size > 0);

    void* top_ptr = hako_get_top_ptr_pdu(pdu_ptr);
    assert(top_ptr != nullptr);

    std::ofstream ofs("point_from_cpp.pdu", std::ios::binary);
    ofs.write(static_cast<const char*>(top_ptr), pdu_size);
    std::cout << "SUCCESS: Generated point_from_cpp.pdu" << std::endl;

    hako_destroy_pdu(pdu_ptr);
}

// Function pointer type for test functions
typedef void (*TestFunction)();

// Test function table
struct TestEntry {
    std::string name;
    TestFunction generate_func;
    TestFunction validate_func;
};

TestEntry test_table[] = {
    { "tf_message", generate_tf_message, validate_tf_message },
    { "point", generate_point_message, validate_point_message },
    // Add new test functions here
    { "", nullptr, nullptr } // Sentinel
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [generate|validate] [tf|point|all]" << std::endl;
        return 1;
    }
    std::string mode = argv[1];
    std::string target = argv[2];

    bool found_target = false;
    for (int i = 0; test_table[i].name != ""; ++i) {
        if (target == "all" || target == test_table[i].name) {
            found_target = true;
            if (mode == "generate") {
                if (test_table[i].generate_func) {
                    test_table[i].generate_func();
                }
            } else if (mode == "validate") {
                if (test_table[i].validate_func) {
                    test_table[i].validate_func();
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
