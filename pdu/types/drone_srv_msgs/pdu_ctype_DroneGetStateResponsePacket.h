#ifndef _pdu_ctype_drone_srv_msgs_DroneGetStateResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneGetStateResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneGetStateResponse.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Pose.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "hako_msgs/pdu_ctype_HakoBatteryStatus.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_DroneGetStateResponse body;
} Hako_DroneGetStateResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGetStateResponsePacket_H_ */
