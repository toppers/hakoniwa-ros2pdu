#ifndef _pdu_cpptype_drone_srv_msgs_DroneSetReadyRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneSetReadyRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneSetReadyRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_DroneSetReadyRequest body;
} HakoCpp_DroneSetReadyRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneSetReadyRequestPacket_HPP_ */
