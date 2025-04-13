#ifndef _pdu_ctype_hako_srv_msgs_AddTwoIntsResponse_H_
#define _pdu_ctype_hako_srv_msgs_AddTwoIntsResponse_H_

#include "pdu_primitive_ctypes.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_int64 sum;
} Hako_AddTwoIntsResponse;

#endif /* _pdu_ctype_hako_srv_msgs_AddTwoIntsResponse_H_ */
