#ifndef _pdu_ctype_drone_srv_msgs_DroneGetStateResponse_H_
#define _pdu_ctype_drone_srv_msgs_DroneGetStateResponse_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Pose.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "hako_msgs/pdu_ctype_HakoBatteryStatus.h"

typedef struct {
        Hako_bool ok;
        Hako_bool is_ready;
        Hako_Pose current_pose;
        Hako_HakoBatteryStatus battery_status;
        char mode[HAKO_STRING_SIZE];
        char message[HAKO_STRING_SIZE];
} Hako_DroneGetStateResponse;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGetStateResponse_H_ */
