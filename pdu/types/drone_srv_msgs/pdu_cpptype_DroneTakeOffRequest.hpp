#ifndef _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequest_HPP_
#define _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_float64 alt_m;
        std::string drone_name;
} HakoCpp_DroneTakeOffRequest;

#endif /* _pdu_cpptype_drone_srv_msgs_DroneTakeOffRequest_HPP_ */
