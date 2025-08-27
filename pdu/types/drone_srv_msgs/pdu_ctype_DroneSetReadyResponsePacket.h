#ifndef _pdu_ctype_drone_srv_msgs_DroneSetReadyResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneSetReadyResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneSetReadyResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_DroneSetReadyResponse body;
} Hako_DroneSetReadyResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneSetReadyResponsePacket_H_ */
