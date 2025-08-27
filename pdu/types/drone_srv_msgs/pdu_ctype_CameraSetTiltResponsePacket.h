#ifndef _pdu_ctype_drone_srv_msgs_CameraSetTiltResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_CameraSetTiltResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_CameraSetTiltResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_CameraSetTiltResponse body;
} Hako_CameraSetTiltResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_CameraSetTiltResponsePacket_H_ */
