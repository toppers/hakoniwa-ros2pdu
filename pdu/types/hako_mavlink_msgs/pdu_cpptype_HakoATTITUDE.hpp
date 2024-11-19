#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoATTITUDE_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoATTITUDE_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 time_boot_ms;
        Hako_float32 roll;
        Hako_float32 pitch;
        Hako_float32 yaw;
        Hako_float32 rollspeed;
        Hako_float32 pitchspeed;
        Hako_float32 yawspeed;
} HakoCpp_HakoATTITUDE;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoATTITUDE_HPP_ */
