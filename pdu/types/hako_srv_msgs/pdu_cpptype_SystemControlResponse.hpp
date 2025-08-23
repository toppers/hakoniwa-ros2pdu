#ifndef _pdu_cpptype_hako_srv_msgs_SystemControlResponse_HPP_
#define _pdu_cpptype_hako_srv_msgs_SystemControlResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 status_code;
        std::string message;
} HakoCpp_SystemControlResponse;

#endif /* _pdu_cpptype_hako_srv_msgs_SystemControlResponse_HPP_ */
