#ifndef _pdu_ctype_pico_msgs_PicoSensor_H_
#define _pdu_ctype_pico_msgs_PicoSensor_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool detect_f;
        Hako_bool detect_r;
        Hako_bool detect_l;
        Hako_bool detect_b;
} Hako_PicoSensor;

#endif /* _pdu_ctype_pico_msgs_PicoSensor_H_ */
