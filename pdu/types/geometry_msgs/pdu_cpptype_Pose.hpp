#ifndef _pdu_cpptype_geometry_msgs_Pose_HPP_
#define _pdu_cpptype_geometry_msgs_Pose_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"

typedef struct {
        HakoCpp_Point position;
        HakoCpp_Quaternion orientation;
} HakoCpp_Pose;

#endif /* _pdu_cpptype_geometry_msgs_Pose_HPP_ */
