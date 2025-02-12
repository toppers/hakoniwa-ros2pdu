#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink2_msgs/pdu_ctype_HakoSERVO_OUTPUT_RAW.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoSERVO_OUTPUT_RAW(Hako_HakoSERVO_OUTPUT_RAW &src,  mavlink_s_e_r_v_o__o_u_t_p_u_t__r_a_w_t &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.port = src.port;
    //primitive convert
    dst.servo1_raw = src.servo1_raw;
    //primitive convert
    dst.servo2_raw = src.servo2_raw;
    //primitive convert
    dst.servo3_raw = src.servo3_raw;
    //primitive convert
    dst.servo4_raw = src.servo4_raw;
    //primitive convert
    dst.servo5_raw = src.servo5_raw;
    //primitive convert
    dst.servo6_raw = src.servo6_raw;
    //primitive convert
    dst.servo7_raw = src.servo7_raw;
    //primitive convert
    dst.servo8_raw = src.servo8_raw;
    //primitive convert
    dst.servo9_raw = src.servo9_raw;
    //primitive convert
    dst.servo10_raw = src.servo10_raw;
    //primitive convert
    dst.servo11_raw = src.servo11_raw;
    //primitive convert
    dst.servo12_raw = src.servo12_raw;
    //primitive convert
    dst.servo13_raw = src.servo13_raw;
    //primitive convert
    dst.servo14_raw = src.servo14_raw;
    //primitive convert
    dst.servo15_raw = src.servo15_raw;
    //primitive convert
    dst.servo16_raw = src.servo16_raw;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoSERVO_OUTPUT_RAW(mavlink_s_e_r_v_o__o_u_t_p_u_t__r_a_w_t &src, Hako_HakoSERVO_OUTPUT_RAW &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive convert
    dst.port = src.port;
    //primitive convert
    dst.servo1_raw = src.servo1_raw;
    //primitive convert
    dst.servo2_raw = src.servo2_raw;
    //primitive convert
    dst.servo3_raw = src.servo3_raw;
    //primitive convert
    dst.servo4_raw = src.servo4_raw;
    //primitive convert
    dst.servo5_raw = src.servo5_raw;
    //primitive convert
    dst.servo6_raw = src.servo6_raw;
    //primitive convert
    dst.servo7_raw = src.servo7_raw;
    //primitive convert
    dst.servo8_raw = src.servo8_raw;
    //primitive convert
    dst.servo9_raw = src.servo9_raw;
    //primitive convert
    dst.servo10_raw = src.servo10_raw;
    //primitive convert
    dst.servo11_raw = src.servo11_raw;
    //primitive convert
    dst.servo12_raw = src.servo12_raw;
    //primitive convert
    dst.servo13_raw = src.servo13_raw;
    //primitive convert
    dst.servo14_raw = src.servo14_raw;
    //primitive convert
    dst.servo15_raw = src.servo15_raw;
    //primitive convert
    dst.servo16_raw = src.servo16_raw;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_ */
