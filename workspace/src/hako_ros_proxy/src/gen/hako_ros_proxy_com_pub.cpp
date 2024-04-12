#include "../com_ros2/hako_ros_proxy_com.hpp"
#include "../com_zenoh/hako_ros_proxy_com_zenoh_pub.hpp"
#include "../hako_ros_proxy_libs.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

/*
 * Publishers
 */
static ROS_NODE_TYPE my_node;
ROS_PROXY_DECLARE_PUBLISHER(geometry_msgs::msg::Twist, TB3RoboModel_sensor_message);
ROS_PROXY_DECLARE_PUBLISHER(geometry_msgs::msg::Twist, TB3RoboModel_actuator_message);

ZENOH_DECLARE_PUBLISHER(TB3RoboModel_sensor_message);

void hako_ros_proxy_com_pub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    ROS_PROXY_CREATE_PUBLISHER(geometry_msgs, Twist, TB3RoboModel_sensor_message);
    ROS_PROXY_CREATE_PUBLISHER(geometry_msgs, Twist, TB3RoboModel_actuator_message);
    ZENOH_CREATE_PUBLISHER(TB3RoboModel_sensor_message);
    return;
}

/*
 * Subscribers
 */
#include "../com_zenoh/hako_ros_proxy_com_zenoh_sub.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

ROS_PROXY_DECLARE_SUBSCRIBER(geometry_msgs::msg::Twist, TB3RoboModel_actuator_message);
ROS_PROXY_DEFINE_SUB_CALLBACK(geometry_msgs, Twist, TB3RoboModel_actuator_message)

ZENOH_DECLARE_SUBSCRIBER(TB3RoboModel_actuator_message);
ZENOH_DEFINE_SUB_CALLBACK(geometry_msgs, Twist, TB3RoboModel_actuator_message)

void hako_ros_proxy_com_sub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    ROS_PROXY_CREATE_SUBSCRIBER(geometry_msgs, Twist, TB3RoboModel_actuator_message);
    ZENOH_CREATE_SUBSCRIBER(TB3RoboModel_actuator_message);

    return;
}