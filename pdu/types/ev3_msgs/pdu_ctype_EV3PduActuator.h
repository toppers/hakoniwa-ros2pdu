#ifndef _pdu_ctype_ev3_msgs_Ev3PduActuator_H_
#define _pdu_ctype_ev3_msgs_Ev3PduActuator_H_

#include "pdu_primitive_ctypes.h"
#include "ev3_msgs/pdu_ctype_Ev3PduActuatorHeader.h"
#include "ev3_msgs/pdu_ctype_Ev3PduMotor.h"

typedef struct {
        Hako_Ev3PduActuatorHeader head;
        Hako_uint8 leds[1];
        Hako_Ev3PduMotor motors[3];
        Hako_uint32 gyro_reset;
} Hako_Ev3PduActuator;

#endif /* _pdu_ctype_ev3_msgs_Ev3PduActuator_H_ */
