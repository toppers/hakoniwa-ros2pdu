#ifndef _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequest_HPP_
#define _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

typedef struct {
        HakoCpp_ServiceRequestHeader header;
        Hako_int64 a;
        Hako_int64 b;
} HakoCpp_AddTwoIntsRequest;

#endif /* _pdu_cpptype_hako_srv_msgs_AddTwoIntsRequest_HPP_ */
