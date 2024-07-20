#ifndef _pdu_cpptype_sensor_msgs_PointCloud2_HPP_
#define _pdu_cpptype_sensor_msgs_PointCloud2_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "sensor_msgs/pdu_cpptype_PointField.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        std::vector<HakoCpp_PointField> fields;
        Hako_bool is_bigendian;
        Hako_uint32 point_step;
        Hako_uint32 row_step;
        std::vector<Hako_uint8> data;
        Hako_bool is_dense;
} HakoCpp_PointCloud2;

#endif /* _pdu_cpptype_sensor_msgs_PointCloud2_HPP_ */
