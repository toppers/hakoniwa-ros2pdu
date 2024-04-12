#include <iostream>

#ifdef MROS2
#include "hako_ros_proxy_com_mros2.hpp"
#else
#include "com_ros2/ros2/hako_ros_proxy_com_ros2.hpp"
#endif
#include "com_zenoh/hako_ros_proxy_com_zenoh.hpp"

int main(int argc, char *argv[]) 
{
    const char *node_name = "hako_ros_proxy_node";
    std::cout << "START:" << node_name << std::endl;

    if (!hako_ros_proxy_zenoh_initialize()) {
        return -1;
    }

    ROS_NODE_TYPE node = hako_ros_proxy_init(argc, argv, node_name);

    hako_ros_proxy_com_ros2_init(node);
    hako_ros_proxy_com_zenoh_init(node);

    HAKO_ROS_PROXY_WALL_RATE(rate, 100ms);
    while (hako_ros_proxy_ok()) {
        hako_ros_proxy_spin(node);
        HAKO_ROS_PROXY_WALL_RATE_sleep(rate);
    }
    hako_ros_proxy_zenoh_finalize();
    std::cout << "EXIT" << std::endl;

    hako_ros_proxy_shutdown();
    return 0;
}

