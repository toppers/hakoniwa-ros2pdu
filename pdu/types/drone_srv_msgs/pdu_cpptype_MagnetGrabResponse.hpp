#ifndef _pdu_cpptype_drone_srv_msgs_MagnetGrabResponse_HPP_
#define _pdu_cpptype_drone_srv_msgs_MagnetGrabResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_bool ok;
        Hako_bool magnet_on;
        Hako_bool contact_on;
        std::string message;
} HakoCpp_MagnetGrabResponse;

#endif /* _pdu_cpptype_drone_srv_msgs_MagnetGrabResponse_HPP_ */
