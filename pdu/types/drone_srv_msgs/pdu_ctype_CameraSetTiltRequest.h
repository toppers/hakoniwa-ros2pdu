#ifndef _pdu_ctype_drone_srv_msgs_CameraSetTiltRequest_H_
#define _pdu_ctype_drone_srv_msgs_CameraSetTiltRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
        Hako_float32 tilt_angle_deg;
} Hako_CameraSetTiltRequest;

#endif /* _pdu_ctype_drone_srv_msgs_CameraSetTiltRequest_H_ */
