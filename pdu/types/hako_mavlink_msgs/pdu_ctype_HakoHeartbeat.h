#ifndef _pdu_ctype_hako_mavlink_msgs_HakoHeartbeat_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoHeartbeat_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint8 type;
        Hako_uint8 autopilot;
        Hako_uint8 base_mode;
        Hako_uint32 custom_mode;
        Hako_uint8 system_status;
        Hako_uint8 mavlink_version;
} Hako_HakoHeartbeat;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoHeartbeat_H_ */
