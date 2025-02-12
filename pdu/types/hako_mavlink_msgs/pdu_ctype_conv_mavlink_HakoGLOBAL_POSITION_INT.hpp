#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoGLOBAL_POSITION_INT.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoGLOBAL_POSITION_INT(Hako_HakoGLOBAL_POSITION_INT &src,  mavlink_g_l_o_b_a_l__p_o_s_i_t_i_o_n__i_n_t_t &dst)
{
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.relative_alt = src.relative_alt;
    //primitive convert
    dst.vx = src.vx;
    //primitive convert
    dst.vy = src.vy;
    //primitive convert
    dst.vz = src.vz;
    //primitive convert
    dst.hdg = src.hdg;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoGLOBAL_POSITION_INT(mavlink_g_l_o_b_a_l__p_o_s_i_t_i_o_n__i_n_t_t &src, Hako_HakoGLOBAL_POSITION_INT &dst)
{
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    //primitive convert
    dst.lat = src.lat;
    //primitive convert
    dst.lon = src.lon;
    //primitive convert
    dst.alt = src.alt;
    //primitive convert
    dst.relative_alt = src.relative_alt;
    //primitive convert
    dst.vx = src.vx;
    //primitive convert
    dst.vy = src.vy;
    //primitive convert
    dst.vz = src.vz;
    //primitive convert
    dst.hdg = src.hdg;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_ */
