#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHeartbeat_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHeartbeat_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHeartbeat.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoHeartbeat(Hako_HakoHeartbeat &src,  mavlink_heartbeat_t &dst)
{
    //primitive convert
    dst.type = src.type;
    //primitive convert
    dst.autopilot = src.autopilot;
    //primitive convert
    dst.base_mode = src.base_mode;
    //primitive convert
    dst.custom_mode = src.custom_mode;
    //primitive convert
    dst.system_status = src.system_status;
    //primitive convert
    dst.mavlink_version = src.mavlink_version;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoHeartbeat(mavlink_heartbeat_t &src, Hako_HakoHeartbeat &dst)
{
    //primitive convert
    dst.type = src.type;
    //primitive convert
    dst.autopilot = src.autopilot;
    //primitive convert
    dst.base_mode = src.base_mode;
    //primitive convert
    dst.custom_mode = src.custom_mode;
    //primitive convert
    dst.system_status = src.system_status;
    //primitive convert
    dst.mavlink_version = src.mavlink_version;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHeartbeat_HPP_ */
