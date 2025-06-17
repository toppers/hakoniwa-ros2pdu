#ifndef _pdu_ctype_hako_msgs_DisturbanceWall_H_
#define _pdu_ctype_hako_msgs_DisturbanceWall_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_Point wall_point;
        Hako_Vector3 wall_normal;
} Hako_DisturbanceWall;

#endif /* _pdu_ctype_hako_msgs_DisturbanceWall_H_ */
