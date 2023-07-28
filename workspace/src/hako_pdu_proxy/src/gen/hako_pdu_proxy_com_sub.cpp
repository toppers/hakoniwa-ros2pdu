#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_SUBSCRIBER(geometry_msgs::msg::Twist, TB3RoboModel_cmd_vel);
DEFINE_SUB_CALLBACK(geometry_msgs, Twist, "TB3RoboModel", 0, TB3RoboModel_cmd_vel)

void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_SUBSCRIBER(geometry_msgs, Twist, "TB3RoboModel", 0, TB3RoboModel_cmd_vel);

    return;
}

