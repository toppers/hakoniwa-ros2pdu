#ifndef _pdu_ctype_hako_msgs_ShareObjectOwnerRequest_H_
#define _pdu_ctype_hako_msgs_ShareObjectOwnerRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char object_name[HAKO_STRING_SIZE];
        Hako_uint32 request_type;
        Hako_uint32 new_owner_id;
        Hako_uint64 request_time;
} Hako_ShareObjectOwnerRequest;

#endif /* _pdu_ctype_hako_msgs_ShareObjectOwnerRequest_H_ */
