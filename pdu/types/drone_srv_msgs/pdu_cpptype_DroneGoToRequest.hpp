#ifndef _pdu_cpptype_drone_srv_msgs_DroneGoToRequest_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneGoToRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        std::string drone_name;
        HakoCpp_Vector3 target_pose;
        Hako_float32 speed_m_s;
        Hako_float32 yaw_deg;
        Hako_float32 tolerance_m;
        Hako_float32 timeout_sec;
} HakoCpp_DroneGoToRequest;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneGoToRequest_HPP_ */
