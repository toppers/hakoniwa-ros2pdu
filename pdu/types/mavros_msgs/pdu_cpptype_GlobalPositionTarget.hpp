#ifndef _pdu_cpptype_mavros_msgs_GlobalPositionTarget_HPP_
#define _pdu_cpptype_mavros_msgs_GlobalPositionTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        Hako_uint8 coordinate_frame;
        Hako_uint16 type_mask;
        Hako_float64 latitude;
        Hako_float64 longitude;
        Hako_float32 altitude;
        HakoCpp_Vector3 velocity;
        HakoCpp_Vector3 acceleration_or_force;
        Hako_float32 yaw;
        Hako_float32 yaw_rate;
} HakoCpp_GlobalPositionTarget;

#endif /* _pdu_cpptype_mavros_msgs_GlobalPositionTarget_HPP_ */
