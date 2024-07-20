#ifndef _pdu_cpptype_sensor_msgs_CompressedImage_HPP_
#define _pdu_cpptype_sensor_msgs_CompressedImage_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        std::string format;
        std::vector<Hako_uint8> data;
} HakoCpp_CompressedImage;

#endif /* _pdu_cpptype_sensor_msgs_CompressedImage_HPP_ */
