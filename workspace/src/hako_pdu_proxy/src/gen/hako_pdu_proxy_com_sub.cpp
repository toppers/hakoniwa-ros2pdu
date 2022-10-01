#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

//TODO repeat
#include "can_msgs/pdu_ctype_conv_HakoCan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;

//TODO repeat..
DECLARE_SUBSCRIBER(can_msgs::msg::HakoCan, topic_sub);
DEFINE_SUB_CALLBACK(can_msgs, HakoCan, 0, topic_sub)

void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
 
    //TODO repeat..
    CREATE_SUBSCRIBER(can_msgs::msg::HakoCan, topic_sub);
    return;
}

