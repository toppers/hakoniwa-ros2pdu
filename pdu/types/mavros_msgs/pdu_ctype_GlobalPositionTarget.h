#ifndef _pdu_ctype_mavros_msgs_GlobalPositionTarget_H_
#define _pdu_ctype_mavros_msgs_GlobalPositionTarget_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_uint8 coordinate_frame;
        Hako_uint16 type_mask;
        Hako_float64 latitude;
        Hako_float64 longitude;
        Hako_float32 altitude;
        Hako_Vector3 velocity;
        Hako_Vector3 acceleration_or_force;
        Hako_float32 yaw;
        Hako_float32 yaw_rate;
} Hako_GlobalPositionTarget;

#endif /* _pdu_ctype_mavros_msgs_GlobalPositionTarget_H_ */
