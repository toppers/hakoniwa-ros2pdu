#ifndef _pdu_ctype_drone_srv_msgs_DroneLandResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneLandResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneLandResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_DroneLandResponse body;
} Hako_DroneLandResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneLandResponsePacket_H_ */
