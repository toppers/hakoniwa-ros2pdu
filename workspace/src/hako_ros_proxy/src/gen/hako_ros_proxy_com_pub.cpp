#include "../hako_ros_proxy_com.hpp"
#include "../hako_ros_proxy_libs.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

static ROS_NODE_TYPE my_node;
ROS_PROXY_DECLARE_PUBLISHER(geometry_msgs::msg::Twist, TB3RoboModel_sensor_message);

void hako_ros_proxy_com_pub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    ROS_PROXY_CREATE_PUBLISHER(geometry_msgs, Twist, TB3RoboModel_sensor_message);

    return;
}

void hako_ros_proxy_com_publish(void)
{
    ROS_PROXY_PUBLISH_PDU_TOPIC(geometry_msgs, Twist, TB3RoboModel_sensor_message);
    return;
}
