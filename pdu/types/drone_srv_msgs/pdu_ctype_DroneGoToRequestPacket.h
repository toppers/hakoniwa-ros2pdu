#ifndef _pdu_ctype_drone_srv_msgs_DroneGoToRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneGoToRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneGoToRequest.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_DroneGoToRequest body;
} Hako_DroneGoToRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneGoToRequestPacket_H_ */
