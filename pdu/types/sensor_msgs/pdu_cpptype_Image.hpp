#ifndef _pdu_cpptype_sensor_msgs_Image_HPP_
#define _pdu_cpptype_sensor_msgs_Image_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        std::string encoding;
        Hako_uint8 is_bigendian;
        Hako_uint32 step;
        std::vector<Hako_uint8> data;
} HakoCpp_Image;

#endif /* _pdu_cpptype_sensor_msgs_Image_HPP_ */
