#ifndef _pdu_ctype_hako_mavlink_msgs_HakoHilSensor_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoHilSensor_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint64 time_usec;
        Hako_float32 xacc;
        Hako_float32 yacc;
        Hako_float32 zacc;
        Hako_float32 xgyro;
        Hako_float32 ygyro;
        Hako_float32 zgyro;
        Hako_float32 xmag;
        Hako_float32 ymag;
        Hako_float32 zmag;
        Hako_float32 abs_pressure;
        Hako_float32 diff_pressure;
        Hako_float32 pressure_alt;
        Hako_float32 temperature;
        Hako_uint32 fields_updated;
        Hako_uint8 id;
} Hako_HakoHilSensor;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoHilSensor_H_ */
