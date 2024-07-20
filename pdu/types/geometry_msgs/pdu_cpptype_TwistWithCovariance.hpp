#ifndef _pdu_cpptype_geometry_msgs_TwistWithCovariance_HPP_
#define _pdu_cpptype_geometry_msgs_TwistWithCovariance_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        HakoCpp_Twist twist;
        std::array<Hako_float64, 36> covariance;
} HakoCpp_TwistWithCovariance;

#endif /* _pdu_cpptype_geometry_msgs_TwistWithCovariance_HPP_ */
