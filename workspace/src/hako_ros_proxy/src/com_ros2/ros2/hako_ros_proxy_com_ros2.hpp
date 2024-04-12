#ifndef _HAKO_ROS_PROXY_COM_ROS2_HPP_
#define _HAKO_ROS_PROXY_COM_ROS2_HPP_

#include "rclcpp/rclcpp.hpp"

extern void hako_ros_proxy_com_ros2_init(std::shared_ptr<rclcpp::Node> node);
extern void hako_ros_proxy_com_zenoh_init(std::shared_ptr<rclcpp::Node> node);

#define ROS_NODE_TYPE std::shared_ptr<rclcpp::Node>

using namespace std::chrono_literals;


static inline ROS_NODE_TYPE hako_ros_proxy_init(int argc, char** argv, const char* node_name)
{
    rclcpp::init(argc, argv);
    return rclcpp::Node::make_shared(node_name);
}
#define HAKO_ROS_PROXY_WALL_RATE(var, rate) \
    rclcpp::WallRate var(rate); 

#define HAKO_ROS_PROXY_WALL_RATE_sleep(var) do { \
    var.sleep(); \
} while (0)

static inline bool hako_ros_proxy_ok()
{
    return rclcpp::ok();
}

static inline void hako_ros_proxy_shutdown()
{
    rclcpp::shutdown();
}

static inline void hako_ros_proxy_spin(ROS_NODE_TYPE node)
{
    rclcpp::spin_some(node);
}

#endif /* _HAKO_ROS_PROXY_COM_ROS2_HPP_ */