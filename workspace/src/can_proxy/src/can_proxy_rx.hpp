#ifndef _CAN_PROXY_RX_HPP_
#define _CAN_PROXY_RX_HPP_

#include "rclcpp/rclcpp.hpp"

extern bool can_proxy_rx_init(std::shared_ptr<rclcpp::Node> node);
extern bool can_proxy_rx_publish();

#endif /* _CAN_PROXY_RX_HPP_ */