#ifndef _pdu_ctype_drone_srv_msgs_LiDARScanRequestPacket_H_
#define _pdu_ctype_drone_srv_msgs_LiDARScanRequestPacket_H_

#include "pdu_primitive_ctypes.h"
#include "drone_srv_msgs/pdu_ctype_LiDARScanRequest.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_LiDARScanRequest body;
} Hako_LiDARScanRequestPacket;

#endif /* _pdu_ctype_drone_srv_msgs_LiDARScanRequestPacket_H_ */
