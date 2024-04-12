#ifndef _HAKO_ROS_PROXY_COM_ROS2_PUB_HPP_
#define _HAKO_ROS_PROXY_COM_ROS2_PUB_HPP_

#include "../hako_ros_proxy_ros2_common.hpp"
#include "hako_ros_proxy_com_ros2.hpp"


#define ROS_PROXY_DECLARE_PUBLISHER(type, topic_name) \
    static std::shared_ptr<rclcpp::Publisher<type>> publisher_ ##topic_name

#define ROS_PROXY_PUBLISH_TOPIC(topic_name, msg)   \
do {    \
        ROS_PROXY_PUBLISHER(topic_name)->publish(msg);    \
} while (0)


#endif /* _HAKO_ROS_PROXY_COM_ROS2_PUB_HPP_ */