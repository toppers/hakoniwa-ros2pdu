#ifndef _pdu_cpptype_sensor_msgs_CameraInfo_HPP_
#define _pdu_cpptype_sensor_msgs_CameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "sensor_msgs/pdu_cpptype_RegionOfInterest.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        std::string distortion_model;
        std::vector<Hako_float64> d;
        std::array<Hako_float64, 9> k;
        std::array<Hako_float64, 9> r;
        std::array<Hako_float64, 12> p;
        Hako_uint32 binning_x;
        Hako_uint32 binning_y;
        HakoCpp_RegionOfInterest roi;
} HakoCpp_CameraInfo;

#endif /* _pdu_cpptype_sensor_msgs_CameraInfo_HPP_ */
