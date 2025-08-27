#ifndef _pdu_cpptype_drone_srv_msgs_DroneTakeOffResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneTakeOffResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_DroneTakeOffResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_DroneTakeOffResponse body;
} HakoCpp_DroneTakeOffResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneTakeOffResponsePacket_HPP_ */
