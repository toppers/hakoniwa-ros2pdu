#ifndef _pdu_ctype_hako_srv_msgs_SystemControlResponsePacket_H_
#define _pdu_ctype_hako_srv_msgs_SystemControlResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"
#include "hako_srv_msgs/pdu_ctype_SystemControlResponse.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_SystemControlResponse body;
} Hako_SystemControlResponsePacket;

#endif /* _pdu_ctype_hako_srv_msgs_SystemControlResponsePacket_H_ */
