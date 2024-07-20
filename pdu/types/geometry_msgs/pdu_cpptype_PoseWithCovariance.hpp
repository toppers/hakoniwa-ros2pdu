#ifndef _pdu_cpptype_geometry_msgs_PoseWithCovariance_HPP_
#define _pdu_cpptype_geometry_msgs_PoseWithCovariance_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"

typedef struct {
        HakoCpp_Pose pose;
        std::array<Hako_float64, 36> covariance;
} HakoCpp_PoseWithCovariance;

#endif /* _pdu_cpptype_geometry_msgs_PoseWithCovariance_HPP_ */
