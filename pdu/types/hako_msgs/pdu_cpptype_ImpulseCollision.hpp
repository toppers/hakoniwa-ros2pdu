#ifndef _pdu_cpptype_hako_msgs_ImpulseCollision_HPP_
#define _pdu_cpptype_hako_msgs_ImpulseCollision_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        Hako_bool collision;
        Hako_bool is_target_static;
        Hako_float64 restitution_coefficient;
        HakoCpp_Point self_contact_vector;
        HakoCpp_Vector3 normal;
        HakoCpp_Point target_contact_vector;
        HakoCpp_Vector3 target_velocity;
        HakoCpp_Vector3 target_angular_velocity;
        HakoCpp_Vector3 target_euler;
        HakoCpp_Vector3 target_inertia;
        Hako_float64 target_mass;
} HakoCpp_ImpulseCollision;

#endif /* _pdu_cpptype_hako_msgs_ImpulseCollision_HPP_ */
