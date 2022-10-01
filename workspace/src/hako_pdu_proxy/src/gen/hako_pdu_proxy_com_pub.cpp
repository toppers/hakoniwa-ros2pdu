#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

//TODO repeat
#include "can_msgs/pdu_ctype_conv_HakoCan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;

//TODO repeat
DECLARE_PUBLISHER(can_msgs::msg::HakoCan, sample_topic_name);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;

    //TODO repeat..
    CREATE_PUBLISHER(can_msgs::msg::HakoCan, sample_topic_name);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    //TODO repeat
    PUBLISH_PDU_TOPIC(can_msgs, HakoCan, 0, sample_topic_name);

    return;
}
