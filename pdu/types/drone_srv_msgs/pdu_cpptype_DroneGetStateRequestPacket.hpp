#ifndef _pdu_cpptype_drone_srv_msgs_DroneGetStateRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneGetStateRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneGetStateRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_DroneGetStateRequest body;
} HakoCpp_DroneGetStateRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneGetStateRequestPacket_HPP_ */
