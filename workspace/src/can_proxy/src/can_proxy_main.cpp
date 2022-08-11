#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include "can_proxy_hako.hpp"
#include "can_proxy_rx.hpp"
#include "can_proxy_tx.hpp"
#include <iostream>
#include <string.h>

using namespace std::chrono_literals;
#define HAKO

int main(int argc, char **argv) 
{
    bool is_rx_mode = true;
    if (argc != 2) {
        std::cout << "ARG: {tx|rx}" << std::endl;
        return 1;
    }
    const char *node_name = nullptr;
    if (strncmp("rx", argv[1], 2) == 0) {
        node_name = "can_proxy_rx_node";
    }
    else {
        is_rx_mode = false;
        node_name = "can_proxy_tx_node";
    }
    std::cout << "START:" << node_name << std::endl;
#ifdef HAKO
    can_proxy_hako_init(node_name, 10 * 1000);
#endif
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(node_name);
    can_proxy_rx_init(node);
    rclcpp::WallRate rate(10ms);
    while (rclcpp::ok()) {
#ifdef HAKO
        if (can_proxy_hako_run() == false) {
            break;
        }
#endif
        if (is_rx_mode) {
            can_proxy_rx_publish();
        }
        else {
            //TODO
        }
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

