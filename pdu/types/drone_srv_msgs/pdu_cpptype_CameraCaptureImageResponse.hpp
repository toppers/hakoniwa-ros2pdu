#ifndef _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_
#define _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_bool ok;
        std::vector<Hako_uint8> data;
        std::string message;
} HakoCpp_CameraCaptureImageResponse;

#endif /* _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_ */
