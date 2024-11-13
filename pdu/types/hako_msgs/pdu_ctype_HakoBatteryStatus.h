#ifndef _pdu_ctype_hako_msgs_HakoBatteryStatus_H_
#define _pdu_ctype_hako_msgs_HakoBatteryStatus_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_float64 full_voltage;
        Hako_float64 curr_voltage;
        Hako_float64 curr_temp;
        Hako_uint32 status;
        Hako_uint32 cycles;
} Hako_HakoBatteryStatus;

#endif /* _pdu_ctype_hako_msgs_HakoBatteryStatus_H_ */
