#ifndef _pdu_cpptype_drone_srv_msgs_LiDARScanRequestPacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_LiDARScanRequestPacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_LiDARScanRequest.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        HakoCpp_LiDARScanRequest body;
} HakoCpp_LiDARScanRequestPacket;

#endif /* _pdu_cpptype_drone_srv_msgs_LiDARScanRequestPacket_HPP_ */
