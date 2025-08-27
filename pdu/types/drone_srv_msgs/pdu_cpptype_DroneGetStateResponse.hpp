#ifndef _pdu_cpptype_drone_srv_msgs_DroneGetStateResponse_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneGetStateResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "hako_msgs/pdu_cpptype_HakoBatteryStatus.hpp"

typedef struct {
        Hako_bool ok;
        Hako_bool is_ready;
        HakoCpp_Pose current_pose;
        HakoCpp_HakoBatteryStatus battery_status;
        std::string mode;
        std::string message;
} HakoCpp_DroneGetStateResponse;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneGetStateResponse_HPP_ */
