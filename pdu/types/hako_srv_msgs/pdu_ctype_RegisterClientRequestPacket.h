#ifndef _pdu_ctype_hako_srv_msgs_RegisterClientRequestPacket_H_
#define _pdu_ctype_hako_srv_msgs_RegisterClientRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_RegisterClientRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_RegisterClientRequest body;
} Hako_RegisterClientRequestPacket;

#endif /* _pdu_ctype_hako_srv_msgs_RegisterClientRequestPacket_H_ */
