#ifndef _pdu_ctype_hako_srv_msgs_RegisterClientRequest_H_
#define _pdu_ctype_hako_srv_msgs_RegisterClientRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char service_name[HAKO_STRING_SIZE];
        char client_name[HAKO_STRING_SIZE];
} Hako_RegisterClientRequest;

#endif /* _pdu_ctype_hako_srv_msgs_RegisterClientRequest_H_ */
