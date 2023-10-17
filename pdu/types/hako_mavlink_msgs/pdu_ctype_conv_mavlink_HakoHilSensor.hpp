#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilSensor.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoHilSensor(Hako_HakoHilSensor &src,  mavlink_hil_sensor_t &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.xacc = src.xacc;
    //primitive convert
    dst.yacc = src.yacc;
    //primitive convert
    dst.zacc = src.zacc;
    //primitive convert
    dst.xgyro = src.xgyro;
    //primitive convert
    dst.ygyro = src.ygyro;
    //primitive convert
    dst.zgyro = src.zgyro;
    //primitive convert
    dst.xmag = src.xmag;
    //primitive convert
    dst.ymag = src.ymag;
    //primitive convert
    dst.zmag = src.zmag;
    //primitive convert
    dst.abs_pressure = src.abs_pressure;
    //primitive convert
    dst.diff_pressure = src.diff_pressure;
    //primitive convert
    dst.pressure_alt = src.pressure_alt;
    //primitive convert
    dst.temperature = src.temperature;
    //primitive convert
    dst.fields_updated = src.fields_updated;
    //primitive convert
    dst.id = src.id;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoHilSensor(mavlink_hil_sensor_t &src, Hako_HakoHilSensor &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.xacc = src.xacc;
    //primitive convert
    dst.yacc = src.yacc;
    //primitive convert
    dst.zacc = src.zacc;
    //primitive convert
    dst.xgyro = src.xgyro;
    //primitive convert
    dst.ygyro = src.ygyro;
    //primitive convert
    dst.zgyro = src.zgyro;
    //primitive convert
    dst.xmag = src.xmag;
    //primitive convert
    dst.ymag = src.ymag;
    //primitive convert
    dst.zmag = src.zmag;
    //primitive convert
    dst.abs_pressure = src.abs_pressure;
    //primitive convert
    dst.diff_pressure = src.diff_pressure;
    //primitive convert
    dst.pressure_alt = src.pressure_alt;
    //primitive convert
    dst.temperature = src.temperature;
    //primitive convert
    dst.fields_updated = src.fields_updated;
    //primitive convert
    dst.id = src.id;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilSensor_HPP_ */
