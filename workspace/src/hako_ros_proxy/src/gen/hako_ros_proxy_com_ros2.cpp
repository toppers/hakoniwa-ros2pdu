#include "../com_zenoh/hako_ros_proxy_com_zenoh_pub.hpp"
#include "../com_ros2/ros2/hako_ros_proxy_com_ros2_sub.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

/*
 * RosSides:
 */
ZENOH_DECLARE_PUBLISHER(TB3RoboModel_actuator_message);
ROS_PROXY_DECLARE_SUBSCRIBER(geometry_msgs::msg::Twist, TB3RoboModel_actuator_message);
ROS_PROXY_DEFINE_SUB_CALLBACK(geometry_msgs, Twist, TB3RoboModel_actuator_message)

void hako_ros_proxy_com_ros2_init(ROS_NODE_TYPE node)
{
    ZENOH_CREATE_PUBLISHER(TB3RoboModel_actuator_message);
    ROS_PROXY_CREATE_SUBSCRIBER(node, geometry_msgs, Twist, TB3RoboModel_actuator_message);
    return;
}
