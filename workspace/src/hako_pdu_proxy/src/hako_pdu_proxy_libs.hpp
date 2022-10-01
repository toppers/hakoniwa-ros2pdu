#ifndef _HAKO_PDU_PROXY_LIBS_HPP_
#define _HAKO_PDU_PROXY_LIBS_HPP_

#include <string>
#include <hako.hpp>
#include "can_msgs/pdu_ctype_HakoCan.h"

extern bool hako_pdu_proxy_init(const char *asset_name, HakoTimeType delta_usec);
extern bool hako_pdu_proxy_run(bool &can_step);
extern void hako_pdu_proxy_fin();

//TODO
extern bool hako_pdu_proxy_rx_data(HakoPduChannelIdType pdu_channel, Hako_HakoCan &can_msg);
extern bool hako_pdu_proxy_tx_data(HakoPduChannelIdType pdu_channel, Hako_HakoCan &can_msg);

#endif /* _HAKO_PDU_PROXY_LIBS_HPP_ */