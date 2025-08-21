#ifndef _pdu_cpptype_hako_msgs_MetaPdu_HPP_
#define _pdu_cpptype_hako_msgs_MetaPdu_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 total_len;
        Hako_uint32 magicno;
        Hako_uint16 version;
        Hako_uint16 flags;
        Hako_uint32 meta_request_type;
        Hako_uint64 hako_time_us;
        Hako_uint64 asset_time_us;
        Hako_uint64 real_time_us;
        std::string robot_name;
        Hako_int32 channel_id;
        Hako_uint32 body_len;
} HakoCpp_MetaPdu;

#endif /* _pdu_cpptype_hako_msgs_MetaPdu_HPP_ */
