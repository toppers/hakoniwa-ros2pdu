#include "../hako_ros_proxy_com.hpp"
#include "../hako_ros_proxy_libs.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

static ROS_NODE_TYPE my_node;
ROS_PROXY_DECLARE_SUBSCRIBER(geometry_msgs::msg::Twist, TB3RoboModel_actuator_message);
ROS_PROXY_DEFINE_SUB_CALLBACK(geometry_msgs, Twist, TB3RoboModel_actuator_message)

void hako_ros_proxy_com_sub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    ROS_PROXY_CREATE_SUBSCRIBER(geometry_msgs, Twist, TB3RoboModel_actuator_message);

    return;
}

