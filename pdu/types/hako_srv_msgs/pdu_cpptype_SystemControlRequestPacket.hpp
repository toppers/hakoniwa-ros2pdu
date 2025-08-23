#ifndef _pdu_cpptype_hako_srv_msgs_SystemControlRequestPacket_HPP_
#define _pdu_cpptype_hako_srv_msgs_SystemControlRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"
#include "hako_srv_msgs/pdu_cpptype_SystemControlRequest.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_SystemControlRequest body;
} HakoCpp_SystemControlRequestPacket;

#endif /* _pdu_cpptype_hako_srv_msgs_SystemControlRequestPacket_HPP_ */
