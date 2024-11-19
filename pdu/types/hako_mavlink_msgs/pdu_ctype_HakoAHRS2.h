#ifndef _pdu_ctype_hako_mavlink_msgs_HakoAHRS2_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoAHRS2_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_float32 roll;
        Hako_float32 pitch;
        Hako_float32 yaw;
        Hako_float32 altitude;
        Hako_int32 lat;
        Hako_int32 lng;
} Hako_HakoAHRS2;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoAHRS2_H_ */
