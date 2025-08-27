#ifndef _pdu_cpptype_drone_srv_msgs_MagnetGrabRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_MagnetGrabRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_MagnetGrabRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_MagnetGrabRequest body;
} HakoCpp_MagnetGrabRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_MagnetGrabRequestPacket_HPP_ */
