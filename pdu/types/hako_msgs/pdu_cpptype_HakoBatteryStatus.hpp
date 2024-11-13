#ifndef _pdu_cpptype_hako_msgs_HakoBatteryStatus_HPP_
#define _pdu_cpptype_hako_msgs_HakoBatteryStatus_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_float64 full_voltage;
        Hako_float64 curr_voltage;
        Hako_float64 curr_temp;
        Hako_uint32 status;
        Hako_uint32 cycles;
} HakoCpp_HakoBatteryStatus;

#endif /* _pdu_cpptype_hako_msgs_HakoBatteryStatus_HPP_ */
