#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "sensor_msgs/pdu_ctype_conv_LaserScan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_PUBLISHER(sensor_msgs::msg::LaserScan, TB3RoboModel_scan);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_PUBLISHER(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    PUBLISH_PDU_TOPIC(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);
    return;
}
