#ifndef _pdu_ctype_hako_srv_msgs_AddTwoIntsRequestPacket_H_
#define _pdu_ctype_hako_srv_msgs_AddTwoIntsRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_AddTwoIntsRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_AddTwoIntsRequest body;
} Hako_AddTwoIntsRequestPacket;

#endif /* _pdu_ctype_hako_srv_msgs_AddTwoIntsRequestPacket_H_ */
