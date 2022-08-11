#include <stdio.h>

#include "can_msgs/msg/hako_can.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "pdu_primitive_ctypes.h"
#include "can_proxy_hako.hpp"
#include <iostream>

using namespace std::chrono_literals;
#define HAKO

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
#ifdef HAKO
    can_proxy_hako_init("can_proxy_node", 10 * 1000);
#endif
    auto node = rclcpp::Node::make_shared("can_proxy_node");

    rclcpp::WallRate rate(10ms);
    while (rclcpp::ok()) {
#ifdef HAKO
        if (can_proxy_hako_run() == false) {
            break;
        }
#endif
        rclcpp::spin_some(node);
        rate.sleep();
    }
#ifdef HAKO
    can_proxy_hako_fin();
#endif
    std::cout << "EXIT" << std::endl;

    rclcpp::shutdown();
    return 0;
}

