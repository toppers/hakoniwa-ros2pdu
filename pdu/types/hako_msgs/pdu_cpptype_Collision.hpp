#ifndef _pdu_cpptype_hako_msgs_Collision_HPP_
#define _pdu_cpptype_hako_msgs_Collision_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        Hako_bool collision;
        Hako_uint32 contact_num;
        HakoCpp_Vector3 relative_velocity;
        std::array<HakoCpp_Point, 10> contact_position;
        Hako_float64 restitution_coefficient;
} HakoCpp_Collision;

#endif /* _pdu_cpptype_hako_msgs_Collision_HPP_ */
