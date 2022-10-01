#ifndef _CAN_PROXY_COM_HPP_
#define _CAN_PROXY_COM_HPP_

#define PUBLISHER_NUM   1
typedef struct {
    int pdu_channel;
    const char* topic_name;
} HakoTopicPduMapType;

#include "rclcpp/rclcpp.hpp"

extern void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node);
extern void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node);
extern void hako_pdu_proxy_com_publish(void);


/*
 * internal apis
 */
#define DECLARE_PUBLISHER(type, topic_name) \
    static std::shared_ptr<rclcpp::Publisher<type>> publisher_ ##topic_name
#define PUBLISHER(topic_name) publisher_ ##topic_name
#define CREATE_PUBLISHER(type, topic_name) \
do {    \
    PUBLISHER(topic_name) = my_node->create_publisher<type>(#topic_name, 1);    \
} while (0)

#define PUBLISH_TOPIC(topic_name, msg)   \
do {    \
    PUBLISHER(topic_name)->publish(msg);    \
} while (0)

#define PUBLISH_PDU_TOPIC(pkg, ros_type, channel_id, topic_name) \
do {    \
    auto ros_msg = pkg::msg::ros_type();  \
    Hako_ ##ros_type pdu_msg;   \
    if (hako_pdu_proxy_rx_data((channel_id), pdu_msg)) {    \
        hako_convert_pdu2ros_ ##ros_type (pdu_msg, ros_msg); \
        PUBLISH_TOPIC(topic_name, ros_msg);   \
    }   \
} while (0)


#endif /* _CAN_PROXY_COM_HPP_ */
