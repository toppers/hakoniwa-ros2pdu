#include "can_msgs/msg/hako_can.hpp"
#include "can_proxy_com.hpp"
#include "can_proxy_rx.hpp"
#include <vector>

static std::shared_ptr<rclcpp::Publisher<can_msgs::msg::HakoCan>> publisher[PUBLISHER_NUM];
static std::vector<HakoTopicPduMapType> hako_topic_pdu_map;

bool can_proxy_rx_init(std::shared_ptr<rclcpp::Node> node)
{
    //TODO config file loader
    HakoTopicPduMapType map_data;
    map_data.pdu_channel = 0;
    map_data.topic_name = "hako_can_message";
    hako_topic_pdu_map.push_back(map_data);

    for(int i = 0; i < (int)hako_topic_pdu_map.size(); ++i) {
        publisher[i] = node->create_publisher<can_msgs::msg::HakoCan>(hako_topic_pdu_map[i].topic_name, 1);
    }
    return true;
}

bool can_proxy_rx_publish()
{
    auto can_msg = can_msgs::msg::HakoCan();
    for(int i = 0; i < (int)hako_topic_pdu_map.size(); ++i) {
        can_msg.head.dlc = 8;
        can_msg.head.ide = 1;
        can_msg.head.rtr = 0;
        can_msg.head.canid = 0x111;
        can_msg.body.data[0] = 'H';
        can_msg.body.data[1] = 'e';
        can_msg.body.data[2] = 'l';
        can_msg.body.data[3] = 'l';
        can_msg.body.data[4] = 'o';
        can_msg.body.data[5] = ' ';
        publisher[i]->publish(can_msg);
    }
    return true;
}