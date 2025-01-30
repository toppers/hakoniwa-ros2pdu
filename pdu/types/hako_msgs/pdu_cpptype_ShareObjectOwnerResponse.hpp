#ifndef _pdu_cpptype_hako_msgs_ShareObjectOwnerResponse_HPP_
#define _pdu_cpptype_hako_msgs_ShareObjectOwnerResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string object_name;
        Hako_uint32 request_type;
        Hako_uint32 owner_id;
        Hako_bool accepted;
} HakoCpp_ShareObjectOwnerResponse;

#endif /* _pdu_cpptype_hako_msgs_ShareObjectOwnerResponse_HPP_ */
