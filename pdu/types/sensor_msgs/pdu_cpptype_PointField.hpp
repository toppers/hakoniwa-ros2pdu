#ifndef _pdu_cpptype_sensor_msgs_PointField_HPP_
#define _pdu_cpptype_sensor_msgs_PointField_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string name;
        Hako_uint32 offset;
        Hako_uint8 datatype;
        Hako_uint32 count;
} HakoCpp_PointField;

#endif /* _pdu_cpptype_sensor_msgs_PointField_HPP_ */
