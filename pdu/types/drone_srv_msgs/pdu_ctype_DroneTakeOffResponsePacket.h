#ifndef _pdu_ctype_drone_srv_msgs_DroneTakeOffResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneTakeOffResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneTakeOffResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_DroneTakeOffResponse body;
} Hako_DroneTakeOffResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneTakeOffResponsePacket_H_ */
