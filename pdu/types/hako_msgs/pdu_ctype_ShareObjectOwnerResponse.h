#ifndef _pdu_ctype_hako_msgs_ShareObjectOwnerResponse_H_
#define _pdu_ctype_hako_msgs_ShareObjectOwnerResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char object_name[HAKO_STRING_SIZE];
        Hako_uint32 request_type;
        Hako_uint32 owner_id;
        Hako_bool accepted;
} Hako_ShareObjectOwnerResponse;

#endif /* _pdu_ctype_hako_msgs_ShareObjectOwnerResponse_H_ */
