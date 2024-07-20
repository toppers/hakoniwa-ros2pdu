#ifndef _pdu_cpptype_sensor_msgs_RegionOfInterest_HPP_
#define _pdu_cpptype_sensor_msgs_RegionOfInterest_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 x_offset;
        Hako_uint32 y_offset;
        Hako_uint32 height;
        Hako_uint32 width;
        Hako_bool do_rectify;
} HakoCpp_RegionOfInterest;

#endif /* _pdu_cpptype_sensor_msgs_RegionOfInterest_HPP_ */
