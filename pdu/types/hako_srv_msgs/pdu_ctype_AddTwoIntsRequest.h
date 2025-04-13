#ifndef _pdu_ctype_hako_srv_msgs_AddTwoIntsRequest_H_
#define _pdu_ctype_hako_srv_msgs_AddTwoIntsRequest_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"

typedef struct {
        Hako_ServiceRequestHeader header;
        Hako_int64 a;
        Hako_int64 b;
} Hako_AddTwoIntsRequest;

#endif /* _pdu_ctype_hako_srv_msgs_AddTwoIntsRequest_H_ */
