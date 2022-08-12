#include "can_msgs/msg/hako_can.hpp"
#include "can_proxy_com.hpp"
#include "can_proxy_rx.hpp"
#include "can_proxy_hako.hpp"
#include "can_msgs/pdu_ctype_HakoCan.h"
#include <vector>

static std::shared_ptr<rclcpp::Publisher<can_msgs::msg::HakoCan>> publisher[PUBLISHER_NUM];
static std::vector<HakoTopicPduMapType> hako_topic_pdu_map;
static std::shared_ptr<rclcpp::Node> my_node;

bool can_proxy_rx_init(std::shared_ptr<rclcpp::Node> node)
{
    //TODO config file loader
    HakoTopicPduMapType map_data;
    map_data.pdu_channel = 0;
    map_data.topic_name = "hako_can_message";
    hako_topic_pdu_map.push_back(map_data);
    my_node = node;
    return true;
}

static void create_publisher(int index, Hako_HakoCan &can_msg)
{
    char topic_name[4096];
    int size = snprintf(topic_name, sizeof(topic_name), "channel%u/CAN_IDE%u_RTR%u_DLC%u_0x%x", 
        can_msg.head.channel, can_msg.head.ide, can_msg.head.rtr, can_msg.head.dlc, can_msg.head.canid);
    char *p = new char[size+1];
    memset(p, 0, size+1);
    memcpy(p, topic_name, size);
    hako_topic_pdu_map[index].topic_name = topic_name;
    publisher[index] = my_node->create_publisher<can_msgs::msg::HakoCan>(hako_topic_pdu_map[index].topic_name, 1);
    return;
}

bool can_proxy_rx_publish()
{
    auto can_msg = can_msgs::msg::HakoCan();
    Hako_HakoCan hako_can_msg;
    for(int i = 0; i < (int)hako_topic_pdu_map.size(); ++i) {
        if (can_proxy_hako_rx_data(hako_topic_pdu_map[i].pdu_channel, hako_can_msg)) {
            can_msg.head.dlc = hako_can_msg.head.dlc;
            can_msg.head.ide = hako_can_msg.head.ide;
            can_msg.head.rtr = hako_can_msg.head.rtr;
            can_msg.head.canid = hako_can_msg.head.canid;
            for (int j = 0; j < 8; j++) {
                can_msg.body.data[j] = hako_can_msg.body.data[j];
            }
            if (publisher[i] == nullptr) {
                create_publisher(i, hako_can_msg);
            }
            else {
                publisher[i]->publish(can_msg);
            }
        }
    }
    return true;
}