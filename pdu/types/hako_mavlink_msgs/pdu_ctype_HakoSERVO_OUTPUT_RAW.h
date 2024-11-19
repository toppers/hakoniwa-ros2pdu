#ifndef _pdu_ctype_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_H_

#include "pdu_primitive_ctypes.h"

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
} Hako_HakoSERVO_OUTPUT_RAW;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_H_ */
