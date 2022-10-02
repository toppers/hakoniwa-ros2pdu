#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "std_msgs/pdu_ctype_conv_String.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_SUBSCRIBER(std_msgs::msg::String, hello_wait_publish);
DEFINE_SUB_CALLBACK(std_msgs, String, 0, hello_wait_publish)

void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_SUBSCRIBER(std_msgs::msg::String, hello_wait_publish);

    return;
}

