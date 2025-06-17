#ifndef _pdu_cpptype_hako_msgs_DisturbanceWall_HPP_
#define _pdu_cpptype_hako_msgs_DisturbanceWall_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        HakoCpp_Point wall_point;
        HakoCpp_Vector3 wall_normal;
} HakoCpp_DisturbanceWall;

#endif /* _pdu_cpptype_hako_msgs_DisturbanceWall_HPP_ */
