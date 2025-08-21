#ifndef _pdu_ctype_hako_srv_msgs_RegisterClientResponse_H_
#define _pdu_ctype_hako_srv_msgs_RegisterClientResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 service_id;
        Hako_uint32 client_id;
        Hako_uint32 request_channel_id;
        Hako_uint32 response_channel_id;
} Hako_RegisterClientResponse;

#endif /* _pdu_ctype_hako_srv_msgs_RegisterClientResponse_H_ */
