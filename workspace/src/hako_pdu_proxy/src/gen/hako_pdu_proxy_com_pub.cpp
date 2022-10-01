#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_PUBLISHER(geometry_msgs::msg::Twist, TB3RoboModel_cmd_vel);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_PUBLISHER(geometry_msgs::msg::Twist, TB3RoboModel_cmd_vel);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    PUBLISH_PDU_TOPIC(geometry_msgs, Twist, 0, TB3RoboModel_cmd_vel);
    return;
}
