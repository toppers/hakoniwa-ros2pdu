#ifndef _pdu_ctype_drone_srv_msgs_CameraSetTiltRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_CameraSetTiltRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_CameraSetTiltRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_CameraSetTiltRequest body;
} Hako_CameraSetTiltRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_CameraSetTiltRequestPacket_H_ */
