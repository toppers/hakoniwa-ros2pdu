#ifndef _pdu_ctype_drone_srv_msgs_DroneGoToRequest_H_
#define _pdu_ctype_drone_srv_msgs_DroneGoToRequest_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
        Hako_Vector3 target_pose;
        Hako_float32 speed_m_s;
        Hako_float32 yaw_deg;
        Hako_float32 tolerance_m;
        Hako_float32 timeout_sec;
} Hako_DroneGoToRequest;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGoToRequest_H_ */
