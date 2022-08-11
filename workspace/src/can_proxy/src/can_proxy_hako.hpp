#ifndef _CAN_PROXY_HAKO_HPP_
#define _CAN_PROXY_HAKO_HPP_

#include <string>
#include <hako.hpp>
#include "can_msgs/pdu_ctype_HakoCan.h"

extern bool can_proxy_hako_init(const char *asset_name, HakoTimeType delta_usec);
extern bool can_proxy_hako_run(bool &can_step);
extern void can_proxy_hako_fin();
extern bool can_proxy_hako_rx_data(HakoPduChannelIdType pdu_channel, Hako_HakoCan &can_msg);
extern bool can_proxy_hako_tx_data(HakoPduChannelIdType pdu_channel, Hako_HakoCan &can_msg);

#endif /* _CAN_PROXY_HAKO_HPP_ */