#ifndef _pdu_ctype_drone_srv_msgs_DroneLandRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneLandRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneLandRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_DroneLandRequest body;
} Hako_DroneLandRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneLandRequestPacket_H_ */
