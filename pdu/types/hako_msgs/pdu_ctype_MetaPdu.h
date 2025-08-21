#ifndef _pdu_ctype_hako_msgs_MetaPdu_H_
#define _pdu_ctype_hako_msgs_MetaPdu_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 total_len;
        Hako_uint32 magicno;
        Hako_uint16 version;
        Hako_uint16 flags;
        Hako_uint32 meta_request_type;
        Hako_uint64 hako_time_us;
        Hako_uint64 asset_time_us;
        Hako_uint64 real_time_us;
        char robot_name[HAKO_STRING_SIZE];
        Hako_int32 channel_id;
        Hako_uint32 body_len;
} Hako_MetaPdu;

#endif /* _pdu_ctype_hako_msgs_MetaPdu_H_ */
