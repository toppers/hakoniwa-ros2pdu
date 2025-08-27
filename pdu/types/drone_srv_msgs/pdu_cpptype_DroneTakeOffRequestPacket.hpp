#ifndef _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneTakeOffRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_DroneTakeOffRequest body;
} HakoCpp_DroneTakeOffRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequestPacket_HPP_ */
