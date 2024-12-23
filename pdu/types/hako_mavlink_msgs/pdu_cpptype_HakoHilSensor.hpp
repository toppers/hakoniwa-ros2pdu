#ifndef _pdu_cpptype_hako_mavlink_msgs_HakoHilSensor_HPP_
#define _pdu_cpptype_hako_mavlink_msgs_HakoHilSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

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
} HakoCpp_HakoHilSensor;

#endif /* _pdu_cpptype_hako_mavlink_msgs_HakoHilSensor_HPP_ */
