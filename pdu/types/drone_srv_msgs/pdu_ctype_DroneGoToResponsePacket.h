#ifndef _pdu_ctype_drone_srv_msgs_DroneGoToResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneGoToResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneGoToResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_DroneGoToResponse body;
} Hako_DroneGoToResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGoToResponsePacket_H_ */
