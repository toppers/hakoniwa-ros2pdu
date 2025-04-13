#ifndef _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponse_HPP_
#define _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        Hako_int64 sum;
} HakoCpp_AddTwoIntsResponse;

#endif /* _pdu_cpptype_hako_srv_msgs_AddTwoIntsResponse_HPP_ */
