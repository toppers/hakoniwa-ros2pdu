#ifndef _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_CameraCaptureImageResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_CameraCaptureImageResponse body;
} Hako_CameraCaptureImageResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_ */
