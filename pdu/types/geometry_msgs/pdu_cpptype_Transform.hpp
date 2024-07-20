#ifndef _pdu_cpptype_geometry_msgs_Transform_HPP_
#define _pdu_cpptype_geometry_msgs_Transform_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        HakoCpp_Vector3 translation;
        HakoCpp_Quaternion rotation;
} HakoCpp_Transform;

#endif /* _pdu_cpptype_geometry_msgs_Transform_HPP_ */
