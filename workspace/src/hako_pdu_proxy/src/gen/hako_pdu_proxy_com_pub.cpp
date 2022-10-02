#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "std_msgs/pdu_ctype_conv_String.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_PUBLISHER(std_msgs::msg::String, hello_wait);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_PUBLISHER(std_msgs, String, 1, hello_wait);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    PUBLISH_PDU_TOPIC(std_msgs, String, 1, hello_wait);
    return;
}
