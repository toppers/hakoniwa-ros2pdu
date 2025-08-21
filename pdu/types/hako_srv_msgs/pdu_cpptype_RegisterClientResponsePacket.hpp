#ifndef _pdu_cpptype_hako_srv_msgs_RegisterClientResponsePacket_HPP_
#define _pdu_cpptype_hako_srv_msgs_RegisterClientResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_RegisterClientResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_RegisterClientResponse body;
} HakoCpp_RegisterClientResponsePacket;

#endif /* _pdu_cpptype_hako_srv_msgs_RegisterClientResponsePacket_HPP_ */
