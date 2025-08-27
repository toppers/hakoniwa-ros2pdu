#ifndef _pdu_ctype_drone_srv_msgs_DroneSetReadyRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneSetReadyRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneSetReadyRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_DroneSetReadyRequest body;
} Hako_DroneSetReadyRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneSetReadyRequestPacket_H_ */
