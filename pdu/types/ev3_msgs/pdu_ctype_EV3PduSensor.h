#ifndef _pdu_ctype_ev3_msgs_Ev3PduSensor_H_
#define _pdu_ctype_ev3_msgs_Ev3PduSensor_H_

#include "pdu_primitive_ctypes.h"
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
#include "ev3_msgs/pdu_ctype_Ev3PduSensorHeader.h"
#include "ev3_msgs/pdu_ctype_Ev3PduTouchSensor.h"

typedef struct {
        Hako_Ev3PduSensorHeader head;
        Hako_uint8 buttons[1];
        Hako_Ev3PduColorSensor color_sensors[2];
        Hako_Ev3PduTouchSensor touch_sensors[2];
        Hako_uint32 motor_angle[3];
        Hako_int32 gyro_degree;
        Hako_int32 gyro_degree_rate;
        Hako_uint32 sensor_ultrasonic;
        Hako_float64 gps_lat;
        Hako_float64 gps_lon;
} Hako_Ev3PduSensor;

#endif /* _pdu_ctype_ev3_msgs_Ev3PduSensor_H_ */
