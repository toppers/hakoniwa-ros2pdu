#ifndef _pdu_cpptype_hako_msgs_DisturbanceBoundary_HPP_
#define _pdu_cpptype_hako_msgs_DisturbanceBoundary_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        HakoCpp_Point boundary_point;
        HakoCpp_Vector3 boundary_normal;
} HakoCpp_DisturbanceBoundary;

#endif /* _pdu_cpptype_hako_msgs_DisturbanceBoundary_HPP_ */
