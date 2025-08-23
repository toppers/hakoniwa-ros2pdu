#ifndef _pdu_cpptype_hako_srv_msgs_SystemControlResponsePacket_HPP_
#define _pdu_cpptype_hako_srv_msgs_SystemControlResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"
#include "hako_srv_msgs/pdu_cpptype_SystemControlResponse.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_SystemControlResponse body;
} HakoCpp_SystemControlResponsePacket;

#endif /* _pdu_cpptype_hako_srv_msgs_SystemControlResponsePacket_HPP_ */
