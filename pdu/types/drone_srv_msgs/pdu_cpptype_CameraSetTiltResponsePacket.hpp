#ifndef _pdu_cpptype_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_CameraSetTiltResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_CameraSetTiltResponse body;
} HakoCpp_CameraSetTiltResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_ */
