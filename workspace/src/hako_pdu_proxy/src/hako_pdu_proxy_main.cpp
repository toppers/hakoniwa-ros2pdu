#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include "hako_pdu_proxy_libs.hpp"
#include "hako_pdu_proxy_com.hpp"
#include <iostream>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
    const char *node_name = "hako_pdu_proxy_node";
    std::cout << "START:" << node_name << std::endl;
    hako_pdu_proxy_init(node_name, 100 * 1000);
    ROS_NODE_TYPE node = hako_pdu_proxy_ros_init(argc, argv, node_name);
    /*
     * create publishers
     */
    hako_pdu_proxy_com_pub_init(node);

    /*
     * create subscriptions
     */
    hako_pdu_proxy_com_sub_init(node);

    HAKO_PDU_PROXY_ROS_WALL_RATE(rate, 100ms)

    while (hako_pdu_proxy_ros_ok()) {
        bool can_step = false;
        if (hako_pdu_proxy_run(can_step) == false) {
            break;
        }
        if (can_step) {
            /*
            * publish topic from pdu
            */
            hako_pdu_proxy_com_publish();
        }

        hako_pdu_proxy_ros_spin(node);
        HAKO_PDU_PROXY_ROS_WALL_RATE_sleep(rate);
    }
    hako_pdu_proxy_fin();
    std::cout << "EXIT" << std::endl;

    hako_pdu_proxy_ros_shutdown();
    return 0;
}

