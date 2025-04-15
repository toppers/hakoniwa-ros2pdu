#ifndef _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponsePacket_HPP_
#define _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_AddTwoIntsResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_AddTwoIntsResponse body;
} HakoCpp_AddTwoIntsResponsePacket;

#endif /* _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponsePacket_HPP_ */
