#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include "hako_pdu_proxy_libs.hpp"
#include "hako_pdu_proxy_rx.hpp"
#include "hako_pdu_proxy_tx.hpp"
#include <iostream>
#include <string.h>

using namespace std::chrono_literals;


int main(int argc, char **argv) 
{
    const char *node_name = "hako_pdu_proxy_node";
    std::cout << "START:" << node_name << std::endl;
    hako_pdu_proxy_init(node_name, 100 * 1000);
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(node_name);

    /*
     * TODO pub advertisze
     */
    //can_proxy_rx_init(node);
    /*
     * TODO sub advertisze
     */

    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
        bool can_step = false;
        if (hako_pdu_proxy_run(can_step) == false) {
            break;
        }

        /*
         * TODO pub run
         */

        rclcpp::spin_some(node);
        rate.sleep();
    }
    hako_pdu_proxy_fin();
    std::cout << "EXIT" << std::endl;

    rclcpp::shutdown();
    return 0;
}

