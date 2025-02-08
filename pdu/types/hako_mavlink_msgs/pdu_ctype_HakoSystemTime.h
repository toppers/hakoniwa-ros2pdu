#ifndef _pdu_ctype_hako_mavlink_msgs_HakoSystemTime_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoSystemTime_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint64 time_unix_usec;
        Hako_uint64 time_boot_ms;
} Hako_HakoSystemTime;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoSystemTime_H_ */
