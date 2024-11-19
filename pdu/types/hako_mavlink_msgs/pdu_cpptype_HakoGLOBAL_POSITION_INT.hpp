#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 time_boot_ms;
        Hako_int32 lat;
        Hako_int32 lon;
        Hako_int32 alt;
        Hako_int32 relative_alt;
        Hako_int16 vx;
        Hako_int16 vy;
        Hako_int16 vz;
        Hako_uint16 hdg;
} HakoCpp_HakoGLOBAL_POSITION_INT;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_ */
