#ifndef _pdu_cpptype_drone_srv_msgs_DroneGetStateResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneGetStateResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneGetStateResponse.hpp"
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "hako_msgs/pdu_cpptype_HakoBatteryStatus.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_DroneGetStateResponse body;
} HakoCpp_DroneGetStateResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneGetStateResponsePacket_HPP_ */
