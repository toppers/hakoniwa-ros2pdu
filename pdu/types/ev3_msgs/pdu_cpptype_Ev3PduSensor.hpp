#ifndef _pdu_cpptype_ev3_msgs_Ev3PduSensor_HPP_
#define _pdu_cpptype_ev3_msgs_Ev3PduSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "ev3_msgs/pdu_cpptype_Ev3PduColorSensor.hpp"
#include "ev3_msgs/pdu_cpptype_Ev3PduSensorHeader.hpp"
#include "ev3_msgs/pdu_cpptype_Ev3PduTouchSensor.hpp"

typedef struct {
        HakoCpp_Ev3PduSensorHeader head;
        std::array<Hako_uint8, 1> buttons;
        std::array<HakoCpp_Ev3PduColorSensor, 2> color_sensors;
        std::array<HakoCpp_Ev3PduTouchSensor, 2> touch_sensors;
        std::array<Hako_uint32, 3> motor_angle;
        Hako_int32 gyro_degree;
        Hako_int32 gyro_degree_rate;
        Hako_uint32 sensor_ultrasonic;
        Hako_float64 gps_lat;
        Hako_float64 gps_lon;
} HakoCpp_Ev3PduSensor;

#endif /* _pdu_cpptype_ev3_msgs_Ev3PduSensor_HPP_ */
