#ifndef _pdu_cpptype_drone_srv_msgs_CameraSetTiltRequest_HPP_
#define _pdu_cpptype_drone_srv_msgs_CameraSetTiltRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string drone_name;
        Hako_float32 tilt_angle_deg;
} HakoCpp_CameraSetTiltRequest;

#endif /* _pdu_cpptype_drone_srv_msgs_CameraSetTiltRequest_HPP_ */
