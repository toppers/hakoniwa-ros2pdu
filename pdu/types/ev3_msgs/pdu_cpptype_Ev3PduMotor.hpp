#ifndef _pdu_cpptype_ev3_msgs_Ev3PduMotor_HPP_
#define _pdu_cpptype_ev3_msgs_Ev3PduMotor_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_int32 power;
        Hako_uint32 stop;
        Hako_uint32 reset_angle;
} HakoCpp_Ev3PduMotor;

#endif /* _pdu_cpptype_ev3_msgs_Ev3PduMotor_HPP_ */
