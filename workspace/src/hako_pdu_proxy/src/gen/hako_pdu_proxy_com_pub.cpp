#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "pico_msgs/pdu_ctype_conv_LightSensor.hpp"

static ROS_NODE_TYPE my_node;
DECLARE_PUBLISHER(pico_msgs::msg::LightSensor, TB3RoboModel_sensor_message);

void hako_pdu_proxy_com_pub_init(ROS_NODE_TYPE node)
{
    my_node = node;
    CREATE_PUBLISHER(pico_msgs, LightSensor, "TB3RoboModel", 1, TB3RoboModel_sensor_message);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    static unsigned long long count = 0;
    PUBLISH_PDU_TOPIC(pico_msgs, LightSensor, "TB3RoboModel", 1, TB3RoboModel_sensor_message, count, 1);
    count++;
    return;
}
