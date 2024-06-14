#ifndef _pdu_ctype_sensor_msgs_Imu_H_
#define _pdu_ctype_sensor_msgs_Imu_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_Quaternion orientation;
        Hako_float64 orientation_covariance[9];
        Hako_Vector3 angular_velocity;
        Hako_float64 angular_velocity_covariance[9];
        Hako_Vector3 linear_acceleration;
        Hako_float64 linear_acceleration_covariance[9];
} Hako_Imu;

#endif /* _pdu_ctype_sensor_msgs_Imu_H_ */
