#ifndef _pdu_cpptype_hako_msgs_MonitorCameraData_HPP_
#define _pdu_cpptype_hako_msgs_MonitorCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "sensor_msgs/pdu_cpptype_CompressedImage.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        Hako_int32 request_id;
        Hako_int32 image_data_length;
        HakoCpp_CompressedImage image;
} HakoCpp_MonitorCameraData;

#endif /* _pdu_cpptype_hako_msgs_MonitorCameraData_HPP_ */
