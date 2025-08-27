#ifndef _pdu_ctype_drone_srv_msgs_DroneTakeOffRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_DroneTakeOffRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_DroneTakeOffRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_DroneTakeOffRequest body;
} Hako_DroneTakeOffRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_DroneTakeOffRequestPacket_H_ */
