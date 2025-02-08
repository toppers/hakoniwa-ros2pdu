#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoSystemTime_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoSystemTime_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint64 time_unix_usec;
        Hako_uint64 time_boot_ms;
} HakoCpp_HakoSystemTime;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoSystemTime_HPP_ */
