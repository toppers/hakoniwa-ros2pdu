#ifndef _pdu_ctype_drone_srv_msgs_MagnetGrabResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_MagnetGrabResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_MagnetGrabResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_MagnetGrabResponse body;
} Hako_MagnetGrabResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_MagnetGrabResponsePacket_H_ */
