#ifndef _pdu_cpptype_drone_srv_msgs_DroneLandResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneLandResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneLandResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_DroneLandResponse body;
} HakoCpp_DroneLandResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneLandResponsePacket_HPP_ */
