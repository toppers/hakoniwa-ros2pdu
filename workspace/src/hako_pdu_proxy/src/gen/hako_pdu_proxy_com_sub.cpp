#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "sensor_msgs/pdu_ctype_conv_LaserScan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_SUBSCRIBER(sensor_msgs::msg::LaserScan, TB3RoboModel_scan);
DEFINE_SUB_CALLBACK(sensor_msgs, LaserScan, 1, TB3RoboModel_scan)

void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_SUBSCRIBER(sensor_msgs::msg::LaserScan, TB3RoboModel_scan);

    return;
}

