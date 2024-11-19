#ifndef _pdu_ctype_hako_mavlink_msgs_HakoATTITUDE_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoATTITUDE_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 time_boot_ms;
        Hako_float32 roll;
        Hako_float32 pitch;
        Hako_float32 yaw;
        Hako_float32 rollspeed;
        Hako_float32 pitchspeed;
        Hako_float32 yawspeed;
} Hako_HakoATTITUDE;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoATTITUDE_H_ */
