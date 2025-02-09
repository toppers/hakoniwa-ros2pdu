#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoHeartbeat_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoHeartbeat_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint8 type;
        Hako_uint8 autopilot;
        Hako_uint8 base_mode;
        Hako_uint32 custom_mode;
        Hako_uint8 system_status;
        Hako_uint8 mavlink_version;
} HakoCpp_HakoHeartbeat;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoHeartbeat_HPP_ */
