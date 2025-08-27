#ifndef _pdu_cpptype_drone_srv_msgs_MagnetGrabRequest_HPP_
#define _pdu_cpptype_drone_srv_msgs_MagnetGrabRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string drone_name;
        Hako_bool grab_on;
        Hako_float32 timeout_sec;
} HakoCpp_MagnetGrabRequest;

#endif /* _pdu_cpptype_drone_srv_msgs_MagnetGrabRequest_HPP_ */
