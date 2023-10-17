#ifndef _pdu_ctype_hako_mavlink_msgs_HakoHilStateQuaternion_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoHilStateQuaternion_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint64 time_usec;
        Hako_float32 attitude_quaternion[4];
        Hako_float32 rollspeed;
        Hako_float32 pitchspeed;
        Hako_float32 yawspeed;
        Hako_int32 lat;
        Hako_int32 lon;
        Hako_int32 alt;
        Hako_int16 vx;
        Hako_int16 vy;
        Hako_int16 vz;
        Hako_uint16 ind_airspeed;
        Hako_uint16 true_airspeed;
        Hako_int16 xacc;
        Hako_int16 yacc;
        Hako_int16 zacc;
} Hako_HakoHilStateQuaternion;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoHilStateQuaternion_H_ */
