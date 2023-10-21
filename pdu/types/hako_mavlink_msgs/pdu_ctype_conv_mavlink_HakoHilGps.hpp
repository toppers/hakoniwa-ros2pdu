#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilGps_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilGps_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilGps.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoHilGps(Hako_HakoHilGps &src,  mavlink_hil_gps_t &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.eph = src.eph;
    //primitive convert
    dst.epv = src.epv;
    //primitive convert
    dst.vel = src.vel;
    //primitive convert
    dst.vn = src.vn;
    //primitive convert
    dst.ve = src.ve;
    //primitive convert
    dst.vd = src.vd;
    //primitive convert
    dst.cog = src.cog;
    //primitive convert
    dst.satellites_visible = src.satellites_visible;
    //primitive convert
    dst.id = src.id;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.fix_type = src.fix_type;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoHilGps(mavlink_hil_gps_t &src, Hako_HakoHilGps &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.eph = src.eph;
    //primitive convert
    dst.epv = src.epv;
    //primitive convert
    dst.vel = src.vel;
    //primitive convert
    dst.vn = src.vn;
    //primitive convert
    dst.ve = src.ve;
    //primitive convert
    dst.vd = src.vd;
    //primitive convert
    dst.cog = src.cog;
    //primitive convert
    dst.satellites_visible = src.satellites_visible;
    //primitive convert
    dst.id = src.id;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.fix_type = src.fix_type;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilGps_HPP_ */
