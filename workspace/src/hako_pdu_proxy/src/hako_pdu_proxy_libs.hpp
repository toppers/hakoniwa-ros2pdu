#ifndef _HAKO_PDU_PROXY_LIBS_HPP_
#define _HAKO_PDU_PROXY_LIBS_HPP_

#include <string>
#include <hako.hpp>
#include "can_msgs/pdu_ctype_HakoCan.h"

extern bool hako_pdu_proxy_init(const char *asset_name, HakoTimeType delta_usec);
extern bool hako_pdu_proxy_run(bool &can_step);
extern void hako_pdu_proxy_fin();

extern bool hako_pdu_proxy_rx_data(const std::string& robo_name, HakoPduChannelIdType pdu_channel, char* pdu_msg, int buflen);
extern bool hako_pdu_proxy_tx_data(const std::string& robo_name, HakoPduChannelIdType pdu_channel, char* pdu_msg, int buflen);
extern bool hako_pdu_proxy_tx_init(const std::string& robo_name, HakoPduChannelIdType pdu_channel, int buflen);

#endif /* _HAKO_PDU_PROXY_LIBS_HPP_ */