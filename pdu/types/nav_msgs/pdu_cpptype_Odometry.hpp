#ifndef _pdu_cpptype_nav_msgs_Odometry_HPP_
#define _pdu_cpptype_nav_msgs_Odometry_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_PoseWithCovariance.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_TwistWithCovariance.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        std::string child_frame_id;
        HakoCpp_PoseWithCovariance pose;
        HakoCpp_TwistWithCovariance twist;
} HakoCpp_Odometry;

#endif /* _pdu_cpptype_nav_msgs_Odometry_HPP_ */
