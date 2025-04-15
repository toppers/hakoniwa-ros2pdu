#ifndef _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequestPacket_HPP_
#define _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_AddTwoIntsRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_AddTwoIntsRequest body;
} HakoCpp_AddTwoIntsRequestPacket;

#endif /* _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequestPacket_HPP_ */
