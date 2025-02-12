#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoAHRS2_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoAHRS2_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoAHRS2.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoAHRS2(Hako_HakoAHRS2 &src,  mavlink_ahrs2_t &dst)
{
    //primitive convert
    dst.roll = src.roll;
    //primitive convert
    dst.pitch = src.pitch;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.altitude = src.altitude;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lng = src.lng;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoAHRS2(mavlink_ahrs2_t &src, Hako_HakoAHRS2 &dst)
{
    //primitive convert
    dst.roll = src.roll;
    //primitive convert
    dst.pitch = src.pitch;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.altitude = src.altitude;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lng = src.lng;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoAHRS2_HPP_ */
