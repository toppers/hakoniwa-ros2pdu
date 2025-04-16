#ifndef _pdu_ctype_hako_srv_msgs_ServiceRequestHeader_H_
#define _pdu_ctype_hako_srv_msgs_ServiceRequestHeader_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 request_id;
        char service_name[HAKO_STRING_SIZE];
        char client_name[HAKO_STRING_SIZE];
        Hako_uint8 opcode;
        Hako_int32 status_poll_interval_msec;
} Hako_ServiceRequestHeader;

#endif /* _pdu_ctype_hako_srv_msgs_ServiceRequestHeader_H_ */
