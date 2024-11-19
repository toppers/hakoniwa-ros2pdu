#ifndef _pdu_ctype_mavros_msgs_AttitudeTarget_H_
#define _pdu_ctype_mavros_msgs_AttitudeTarget_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_uint8 type_mask;
        Hako_Quaternion orientation;
        Hako_Vector3 body_rate;
        Hako_float32 thrust;
} Hako_AttitudeTarget;

#endif /* _pdu_ctype_mavros_msgs_AttitudeTarget_H_ */
