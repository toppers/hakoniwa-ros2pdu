#ifndef _pdu_cpptype_ev3_msgs_Ev3PduActuator_HPP_
#define _pdu_cpptype_ev3_msgs_Ev3PduActuator_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "ev3_msgs/pdu_cpptype_Ev3PduActuatorHeader.hpp"
#include "ev3_msgs/pdu_cpptype_Ev3PduMotor.hpp"

typedef struct {
        HakoCpp_Ev3PduActuatorHeader head;
        std::array<Hako_uint8, 1> leds;
        std::array<HakoCpp_Ev3PduMotor, 3> motors;
        Hako_uint32 gyro_reset;
} HakoCpp_Ev3PduActuator;

#endif /* _pdu_cpptype_ev3_msgs_Ev3PduActuator_HPP_ */
