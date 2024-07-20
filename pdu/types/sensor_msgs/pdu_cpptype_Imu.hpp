#ifndef _pdu_cpptype_sensor_msgs_Imu_HPP_
#define _pdu_cpptype_sensor_msgs_Imu_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        HakoCpp_Quaternion orientation;
        std::array<Hako_float64, 9> orientation_covariance;
        HakoCpp_Vector3 angular_velocity;
        std::array<Hako_float64, 9> angular_velocity_covariance;
        HakoCpp_Vector3 linear_acceleration;
        std::array<Hako_float64, 9> linear_acceleration_covariance;
} HakoCpp_Imu;

#endif /* _pdu_cpptype_sensor_msgs_Imu_HPP_ */
