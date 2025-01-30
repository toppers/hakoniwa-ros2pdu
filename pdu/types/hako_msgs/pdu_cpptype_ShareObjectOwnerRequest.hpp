#ifndef _pdu_cpptype_hako_msgs_ShareObjectOwnerRequest_HPP_
#define _pdu_cpptype_hako_msgs_ShareObjectOwnerRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string object_name;
        Hako_uint32 request_type;
        Hako_uint32 new_owner_id;
        Hako_uint64 request_time;
} HakoCpp_ShareObjectOwnerRequest;

#endif /* _pdu_cpptype_hako_msgs_ShareObjectOwnerRequest_HPP_ */
