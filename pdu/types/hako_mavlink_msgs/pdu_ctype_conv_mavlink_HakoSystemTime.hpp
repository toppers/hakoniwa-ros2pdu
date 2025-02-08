#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoSystemTime_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoSystemTime_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoSystemTime.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoSystemTime(Hako_HakoSystemTime &src,  mavlink_system_time_t &dst)
{
    //primitive convert
    dst.time_unix_usec = src.time_unix_usec;
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoSystemTime(mavlink_system_time_t &src, Hako_HakoSystemTime &dst)
{
    //primitive convert
    dst.time_unix_usec = src.time_unix_usec;
    //primitive convert
    dst.time_boot_ms = src.time_boot_ms;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoSystemTime_HPP_ */
