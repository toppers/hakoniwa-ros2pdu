#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "std_msgs/pdu_ctype_conv_String.hpp"

static ROS_NODE_TYPE my_node;
DECLARE_PUBLISHER(std_msgs::msg::String, SampleRobo_sensor);

void hako_pdu_proxy_com_pub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    CREATE_PUBLISHER(std_msgs, String, "SampleRobo", 1, SampleRobo_sensor);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    static unsigned long long count = 0;
    PUBLISH_PDU_TOPIC(std_msgs, String, "SampleRobo", 1, SampleRobo_sensor, count, 1);
    count++;
    return;
}
