#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

//TODO repeat
#include "can_msgs/pdu_ctype_conv_HakoCan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;

//TODO repeat
static std::shared_ptr<rclcpp::Publisher<can_msgs::msg::HakoCan>> publisher_xxx;


void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;

    //TODO repeat..
    publisher_xxx = my_node->create_publisher<can_msgs::msg::HakoCan>("topic_name", 1);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    //TODO repeat
    auto can_msg = can_msgs::msg::HakoCan();
    Hako_HakoCan hako_can_msg;
    if (hako_pdu_proxy_rx_data(0, hako_can_msg)) {
        hako_convert_pdu2ros_HakoCan(hako_can_msg, can_msg);
        publisher_xxx->publish(can_msg);
    }
    return;
}
