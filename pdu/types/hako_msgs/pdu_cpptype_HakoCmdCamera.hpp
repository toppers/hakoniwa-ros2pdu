#ifndef _pdu_cpptype_hako_msgs_HakoCmdCamera_HPP_
#define _pdu_cpptype_hako_msgs_HakoCmdCamera_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_msgs/pdu_cpptype_HakoCmdHeader.hpp"

typedef struct {
        HakoCpp_HakoCmdHeader header;
        Hako_int32 request_id;
        Hako_int32 encode_type;
} HakoCpp_HakoCmdCamera;

#endif /* _pdu_cpptype_hako_msgs_HakoCmdCamera_HPP_ */
