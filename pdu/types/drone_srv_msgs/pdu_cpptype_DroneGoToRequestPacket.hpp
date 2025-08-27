#ifndef _pdu_cpptype_drone_srv_msgs_DroneGoToRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneGoToRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneGoToRequest.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_DroneGoToRequest body;
} HakoCpp_DroneGoToRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneGoToRequestPacket_HPP_ */
