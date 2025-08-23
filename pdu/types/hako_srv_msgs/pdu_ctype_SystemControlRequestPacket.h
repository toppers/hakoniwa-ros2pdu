#ifndef _pdu_ctype_hako_srv_msgs_SystemControlRequestPacket_H_
#define _pdu_ctype_hako_srv_msgs_SystemControlRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"
#include "hako_srv_msgs/pdu_ctype_SystemControlRequest.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_SystemControlRequest body;
} Hako_SystemControlRequestPacket;

#endif /* _pdu_ctype_hako_srv_msgs_SystemControlRequestPacket_H_ */
