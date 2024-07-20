#ifndef _pdu_cpptype_hako_msgs_HakoDroneCmdTakeoff_HPP_
#define _pdu_cpptype_hako_msgs_HakoDroneCmdTakeoff_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_msgs/pdu_cpptype_HakoDroneCmdHeader.hpp"

typedef struct {
        HakoCpp_HakoDroneCmdHeader header;
        Hako_float64 height;
        Hako_float64 speed;
        Hako_float64 yaw_deg;
} HakoCpp_HakoDroneCmdTakeoff;

#endif /* _pdu_cpptype_hako_msgs_HakoDroneCmdTakeoff_HPP_ */
