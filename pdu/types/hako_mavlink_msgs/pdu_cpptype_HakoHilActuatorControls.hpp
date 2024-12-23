#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoHilActuatorControls_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoHilActuatorControls_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint64 time_usec;
        std::array<Hako_float32, 16> controls;
        Hako_uint8 mode;
        Hako_uint64 flags;
} HakoCpp_HakoHilActuatorControls;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoHilActuatorControls_HPP_ */
