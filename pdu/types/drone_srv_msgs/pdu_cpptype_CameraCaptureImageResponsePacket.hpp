#ifndef _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "drone_srv_msgs/pdu_cpptype_CameraCaptureImageResponse.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_CameraCaptureImageResponse body;
} HakoCpp_CameraCaptureImageResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponsePacket_HPP_ */
