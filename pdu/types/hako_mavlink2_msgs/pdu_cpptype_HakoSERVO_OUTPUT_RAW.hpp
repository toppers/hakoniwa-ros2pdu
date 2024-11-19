#ifndef _pdu_cpptype_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_
#define _pdu_cpptype_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 time_usec;
        Hako_uint8 port;
        Hako_uint16 servo1_raw;
        Hako_uint16 servo2_raw;
        Hako_uint16 servo3_raw;
        Hako_uint16 servo4_raw;
        Hako_uint16 servo5_raw;
        Hako_uint16 servo6_raw;
        Hako_uint16 servo7_raw;
        Hako_uint16 servo8_raw;
        Hako_uint16 servo9_raw;
        Hako_uint16 servo10_raw;
        Hako_uint16 servo11_raw;
        Hako_uint16 servo12_raw;
        Hako_uint16 servo13_raw;
        Hako_uint16 servo14_raw;
        Hako_uint16 servo15_raw;
        Hako_uint16 servo16_raw;
} HakoCpp_HakoSERVO_OUTPUT_RAW;

#endif /* _pdu_cpptype_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_ */
