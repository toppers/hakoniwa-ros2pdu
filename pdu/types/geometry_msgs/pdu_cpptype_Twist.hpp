#ifndef _pdu_cpptype_geometry_msgs_Twist_HPP_
#define _pdu_cpptype_geometry_msgs_Twist_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        HakoCpp_Vector3 linear;
        HakoCpp_Vector3 angular;
} HakoCpp_Twist;

#endif /* _pdu_cpptype_geometry_msgs_Twist_HPP_ */
