#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoATTITUDE_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoATTITUDE_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoATTITUDE.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoATTITUDE(Hako_HakoATTITUDE &src,  mavlink_a_t_t_i_t_u_d_e_t &dst)
{
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    //primitive convert
    dst.roll = src.roll;
    //primitive convert
    dst.pitch = src.pitch;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.rollspeed = src.rollspeed;
    //primitive convert
    dst.pitchspeed = src.pitchspeed;
    //primitive convert
    dst.yawspeed = src.yawspeed;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoATTITUDE(mavlink_a_t_t_i_t_u_d_e_t &src, Hako_HakoATTITUDE &dst)
{
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    //primitive convert
    dst.roll = src.roll;
    //primitive convert
    dst.pitch = src.pitch;
    //primitive convert
    dst.yaw = src.yaw;
    //primitive convert
    dst.rollspeed = src.rollspeed;
    //primitive convert
    dst.pitchspeed = src.pitchspeed;
    //primitive convert
    dst.yawspeed = src.yawspeed;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoATTITUDE_HPP_ */
