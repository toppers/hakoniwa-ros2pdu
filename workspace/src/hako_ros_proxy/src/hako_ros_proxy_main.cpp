#include <stdio.h>

#include "hako_ros_proxy_libs.hpp"
#include "com_ros2/hako_ros_proxy_com.hpp"
#include "com_zenoh/hako_ros_proxy_com_zenoh.hpp"
#include <iostream>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    const char *node_name = "hako_ros_proxy_node";
    std::cout << "START:" << node_name << std::endl;

    if (!hako_ros_proxy_zenoh_initialize()) {
        return -1;
    }

    ROS_NODE_TYPE node = hako_ros_proxy_init(argc, argv, node_name);

    /*
     * create publishers
     */
    hako_ros_proxy_com_pub_init(node);

    /*
     * create subscriptions
     */
    hako_ros_proxy_com_sub_init(node);

    while (hako_ros_proxy_ok()) {
        if (hako_ros_proxy_run() == false) {
            break;
        }
        hako_ros_proxy_spin(node);
    }
    hako_ros_proxy_zenoh_finalize();
    hako_ros_proxy_fin();
    std::cout << "EXIT" << std::endl;

    hako_ros_proxy_shutdown();
    return 0;
}

