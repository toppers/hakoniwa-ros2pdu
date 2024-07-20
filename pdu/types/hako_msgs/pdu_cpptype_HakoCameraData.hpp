#ifndef _pdu_cpptype_hako_msgs_HakoCameraData_HPP_
#define _pdu_cpptype_hako_msgs_HakoCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "sensor_msgs/pdu_cpptype_CompressedImage.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        Hako_int32 request_id;
        HakoCpp_CompressedImage image;
} HakoCpp_HakoCameraData;

#endif /* _pdu_cpptype_hako_msgs_HakoCameraData_HPP_ */
