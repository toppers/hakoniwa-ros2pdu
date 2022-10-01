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

#endif /* _CAN_PROXY_COM_HPP_ */
