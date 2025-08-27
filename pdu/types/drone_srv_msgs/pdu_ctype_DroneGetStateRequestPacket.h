#ifndef _pdu_ctype_drone_srv_msgs_DroneGetStateRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneGetStateRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneGetStateRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_DroneGetStateRequest body;
} Hako_DroneGetStateRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGetStateRequestPacket_H_ */
