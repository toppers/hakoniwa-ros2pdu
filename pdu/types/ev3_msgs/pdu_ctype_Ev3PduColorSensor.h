#ifndef _pdu_ctype_ev3_msgs_Ev3PduColorSensor_H_
#define _pdu_ctype_ev3_msgs_Ev3PduColorSensor_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 color;
        Hako_uint32 reflect;
        Hako_uint32 rgb_r;
        Hako_uint32 rgb_g;
        Hako_uint32 rgb_b;
} Hako_Ev3PduColorSensor;

#endif /* _pdu_ctype_ev3_msgs_Ev3PduColorSensor_H_ */
