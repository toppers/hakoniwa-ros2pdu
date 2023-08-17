#ifndef _pdu_ctype_pico_msgs_LightSensor_H_
#define _pdu_ctype_pico_msgs_LightSensor_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_int16 forward_r;
        Hako_int16 forward_l;
        Hako_int16 left;
        Hako_int16 right;
} Hako_LightSensor;

#endif /* _pdu_ctype_pico_msgs_LightSensor_H_ */
