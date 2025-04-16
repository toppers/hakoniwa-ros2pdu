#ifndef _pdu_cpptype_hako_srv_msgs_ServiceResponseHeader_HPP_
#define _pdu_cpptype_hako_srv_msgs_ServiceResponseHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 request_id;
        std::string service_name;
        std::string client_name;
        Hako_uint8 status;
        Hako_uint8 processing_percentage;
        Hako_int32 result_code;
} HakoCpp_ServiceResponseHeader;

#endif /* _pdu_cpptype_hako_srv_msgs_ServiceResponseHeader_HPP_ */
