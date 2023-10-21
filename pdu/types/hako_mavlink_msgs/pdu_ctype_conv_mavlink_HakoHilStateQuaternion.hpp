#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilStateQuaternion.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion &src,  mavlink_hil_state_quaternion_t &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion); i++) {
        dst.attitude_quaternion[i] = src.attitude_quaternion[i];
    }
    //primitive convert
    dst.rollspeed = src.rollspeed;
    //primitive convert
    dst.pitchspeed = src.pitchspeed;
    //primitive convert
    dst.yawspeed = src.yawspeed;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.vx = src.vx;
    //primitive convert
    dst.vy = src.vy;
    //primitive convert
    dst.vz = src.vz;
    //primitive convert
    dst.ind_airspeed = src.ind_airspeed;
    //primitive convert
    dst.true_airspeed = src.true_airspeed;
    //primitive convert
    dst.xacc = src.xacc;
    //primitive convert
    dst.yacc = src.yacc;
    //primitive convert
    dst.zacc = src.zacc;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoHilStateQuaternion(mavlink_hil_state_quaternion_t &src, Hako_HakoHilStateQuaternion &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion); i++) {
        dst.attitude_quaternion[i] = src.attitude_quaternion[i];
    }
    //primitive convert
    dst.rollspeed = src.rollspeed;
    //primitive convert
    dst.pitchspeed = src.pitchspeed;
    //primitive convert
    dst.yawspeed = src.yawspeed;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.vx = src.vx;
    //primitive convert
    dst.vy = src.vy;
    //primitive convert
    dst.vz = src.vz;
    //primitive convert
    dst.ind_airspeed = src.ind_airspeed;
    //primitive convert
    dst.true_airspeed = src.true_airspeed;
    //primitive convert
    dst.xacc = src.xacc;
    //primitive convert
    dst.yacc = src.yacc;
    //primitive convert
    dst.zacc = src.zacc;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_ */
