#ifndef _pdu_ctype_hako_msgs_DisturbanceBoundary_H_
#define _pdu_ctype_hako_msgs_DisturbanceBoundary_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_Point boundary_point;
        Hako_Vector3 boundary_normal;
} Hako_DisturbanceBoundary;

#endif /* _pdu_ctype_hako_msgs_DisturbanceBoundary_H_ */
