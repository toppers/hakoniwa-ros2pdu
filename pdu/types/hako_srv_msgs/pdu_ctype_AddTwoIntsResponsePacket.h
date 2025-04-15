#ifndef _pdu_ctype_hako_srv_msgs_AddTwoIntsResponsePacket_H_
#define _pdu_ctype_hako_srv_msgs_AddTwoIntsResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_AddTwoIntsResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_AddTwoIntsResponse body;
} Hako_AddTwoIntsResponsePacket;

#endif /* _pdu_ctype_hako_srv_msgs_AddTwoIntsResponsePacket_H_ */
