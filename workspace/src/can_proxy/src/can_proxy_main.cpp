#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include "can_proxy_hako.hpp"
#include "can_proxy_rx.hpp"
#include "can_proxy_tx.hpp"
#include <iostream>
#include <string.h>

using namespace std::chrono_literals;
#define HAKO

static void send_dummy_data()
{
    static int base = 0;
    Hako_HakoCan can_msg;
    can_msg.head.rtr = 0;
    can_msg.head.ide = 1;
    can_msg.head.dlc = 8;
    can_msg.head.channel = 1;
    can_msg.head.dlc = 8;
    can_msg.head.canid = 128;

    can_msg.body.data[0] = 0 + base;
    can_msg.body.data[1] = 1 + base;
    can_msg.body.data[2] = 2 + base;
    can_msg.body.data[3] = 3 + base;
    can_msg.body.data[4] = 4 + base;
    can_msg.body.data[5] = 5 + base;
    can_msg.body.data[6] = 6 + base;
    can_msg.body.data[7] = 7 + base;
    can_proxy_hako_tx_data(0, can_msg);
    base++;
}

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
    can_proxy_hako_init(node_name, 100 * 1000);
#endif
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(node_name);
    can_proxy_rx_init(node);
    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
#ifdef HAKO
        bool can_step = false;
        if (can_proxy_hako_run(can_step) == false) {
            break;
        }
        if (is_rx_mode) {
            can_proxy_rx_publish();
        }
        else {
            //TODO dummy data send
            send_dummy_data();
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

