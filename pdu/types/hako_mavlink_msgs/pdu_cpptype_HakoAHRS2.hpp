#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoAHRS2_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoAHRS2_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_float32 roll;
        Hako_float32 pitch;
        Hako_float32 yaw;
        Hako_float32 altitude;
        Hako_int32 lat;
        Hako_int32 lng;
} HakoCpp_HakoAHRS2;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoAHRS2_HPP_ */
