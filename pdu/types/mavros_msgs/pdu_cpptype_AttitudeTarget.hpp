#ifndef _pdu_cpptype_mavros_msgs_AttitudeTarget_HPP_
#define _pdu_cpptype_mavros_msgs_AttitudeTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        Hako_uint8 type_mask;
        HakoCpp_Quaternion orientation;
        HakoCpp_Vector3 body_rate;
        Hako_float32 thrust;
} HakoCpp_AttitudeTarget;

#endif /* _pdu_cpptype_mavros_msgs_AttitudeTarget_HPP_ */
