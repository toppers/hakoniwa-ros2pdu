#ifndef _pdu_ctype_ev3_msgs_Ev3PduMotor_H_
#define _pdu_ctype_ev3_msgs_Ev3PduMotor_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_int32 power;
        Hako_uint32 stop;
        Hako_uint32 reset_angle;
} Hako_Ev3PduMotor;

#endif /* _pdu_ctype_ev3_msgs_Ev3PduMotor_H_ */
