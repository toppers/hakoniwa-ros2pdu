#ifndef _pdu_ctype_hako_srv_msgs_ServiceResponseHeader_H_
#define _pdu_ctype_hako_srv_msgs_ServiceResponseHeader_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 request_id;
        char service_name[HAKO_STRING_SIZE];
        char client_name[HAKO_STRING_SIZE];
        Hako_uint8 status;
        Hako_uint8 processing_percentage;
        Hako_int32 result_code;
} Hako_ServiceResponseHeader;

#endif /* _pdu_ctype_hako_srv_msgs_ServiceResponseHeader_H_ */
