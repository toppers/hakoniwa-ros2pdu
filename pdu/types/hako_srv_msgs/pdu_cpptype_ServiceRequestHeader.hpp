#ifndef _pdu_cpptype_hako_srv_msgs_ServiceRequestHeader_HPP_
#define _pdu_cpptype_hako_srv_msgs_ServiceRequestHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 request_id;
        std::string service_name;
        std::string client_name;
        Hako_uint8 opcode;
        Hako_int32 status_poll_interval_msec;
} HakoCpp_ServiceRequestHeader;

#endif /* _pdu_cpptype_hako_srv_msgs_ServiceRequestHeader_HPP_ */
