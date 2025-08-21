#ifndef _pdu_cpptype_hako_srv_msgs_RegisterClientResponse_HPP_
#define _pdu_cpptype_hako_srv_msgs_RegisterClientResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 service_id;
        Hako_uint32 client_id;
        Hako_uint32 request_channel_id;
        Hako_uint32 response_channel_id;
} HakoCpp_RegisterClientResponse;

#endif /* _pdu_cpptype_hako_srv_msgs_RegisterClientResponse_HPP_ */
