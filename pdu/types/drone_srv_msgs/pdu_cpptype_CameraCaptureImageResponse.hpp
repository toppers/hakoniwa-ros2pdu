#ifndef _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_
#define _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "sensor_msgs/pdu_cpptype_CompressedImage.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        Hako_bool ok;
        HakoCpp_CompressedImage image;
        std::string message;
} HakoCpp_CameraCaptureImageResponse;

#endif /* _pdu_cpptype_drone_srv_msgs_CameraCaptureImageResponse_HPP_ */
