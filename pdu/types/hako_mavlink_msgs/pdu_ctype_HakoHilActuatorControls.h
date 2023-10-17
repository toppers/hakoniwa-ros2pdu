#ifndef _pdu_ctype_hako_mavlink_msgs_HakoHilActuatorControls_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoHilActuatorControls_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint64 time_usec;
        Hako_float32 controls[16];
        Hako_uint8 mode;
        Hako_uint64 flags;
} Hako_HakoHilActuatorControls;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoHilActuatorControls_H_ */
