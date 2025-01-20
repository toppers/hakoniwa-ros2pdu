#ifndef _pdu_ctype_hako_msgs_ImpulseCollision_H_
#define _pdu_ctype_hako_msgs_ImpulseCollision_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_bool collision;
        Hako_bool is_target_static;
        Hako_float64 restitution_coefficient;
        Hako_Point self_contact_vector;
        Hako_Vector3 normal;
        Hako_Point target_contact_vector;
        Hako_Vector3 target_velocity;
        Hako_Vector3 target_angular_velocity;
        Hako_Vector3 target_euler;
        Hako_Vector3 target_inertia;
        Hako_float64 target_mass;
} Hako_ImpulseCollision;

#endif /* _pdu_ctype_hako_msgs_ImpulseCollision_H_ */
