#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "std_msgs/pdu_ctype_conv_String.hpp"

static ROS_NODE_TYPE my_node;

DECLARE_SUBSCRIBER(std_msgs::msg::String, TB3RoboModel_sensor_message);
DEFINE_SUB_CALLBACK(std_msgs, String, "TB3RoboModel", 0, TB3RoboModel_sensor_message)

void hako_pdu_proxy_com_sub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    CREATE_SUBSCRIBER(std_msgs, String, "TB3RoboModel", 0, TB3RoboModel_sensor_message);

    return;
}

