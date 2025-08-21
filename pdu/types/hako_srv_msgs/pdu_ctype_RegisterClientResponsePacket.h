#ifndef _pdu_ctype_hako_srv_msgs_RegisterClientResponsePacket_H_
#define _pdu_ctype_hako_srv_msgs_RegisterClientResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_RegisterClientResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_RegisterClientResponse body;
} Hako_RegisterClientResponsePacket;

#endif /* _pdu_ctype_hako_srv_msgs_RegisterClientResponsePacket_H_ */
