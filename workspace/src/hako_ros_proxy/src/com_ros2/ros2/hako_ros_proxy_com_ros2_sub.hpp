#ifndef _HAKO_ROS_PROXY_COM_ROS2_SUB_HPP_
#define _HAKO_ROS_PROXY_COM_ROS2_SUB_HPP_

#include "../hako_ros_proxy_ros2_common.hpp"
#include "hako_ros_proxy_com_ros2.hpp"
#include "../../com_zenoh/hako_ros_proxy_com_zenoh_pub.hpp"

#define ROS_PROXY_DECLARE_SUBSCRIBER(type, topic_name) \
    static std::shared_ptr<rclcpp::Subscription<type>> subscriber_ ##topic_name

#define ROS_PROXY_DEFINE_SUB_CALLBACK(pkg, ros_type, topic_name) \
static void ROS_PROXY_SUB_CALLBACK_NAME(topic_name)(const pkg::msg::ros_type::SharedPtr ros_msg) \
{   \
    Hako_ ##ros_type *pdu_msg;   \
    int total_size = hako_convert_ros2pdu_ ##ros_type (*ros_msg, &pdu_msg); \
    ZENOH_PUBLISH_TOPIC(topic_name, (const uint8_t*)HAKO_GET_TOP_PTR(pdu_msg), total_size);  \
    hako_destroy_pdu(pdu_msg); \
}


#endif /* _HAKO_ROS_PROXY_COM_ROS2_SUB_HPP_ */
