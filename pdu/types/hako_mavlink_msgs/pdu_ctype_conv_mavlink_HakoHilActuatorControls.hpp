#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilActuatorControls_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilActuatorControls_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilActuatorControls.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_HakoHilActuatorControls(Hako_HakoHilActuatorControls &src,  mavlink_hil_actuator_controls_t &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_HakoHilActuatorControls, Hako_float32, controls); i++) {
        dst.controls[i] = src.controls[i];
    }
    //primitive convert
    dst.mode = src.mode;
    //primitive convert
    dst.flags = src.flags;
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_HakoHilActuatorControls(mavlink_hil_actuator_controls_t &src, Hako_HakoHilActuatorControls &dst)
{
    //primitive convert
    dst.time_usec = src.time_usec;
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_HakoHilActuatorControls, Hako_float32, controls); i++) {
        dst.controls[i] = src.controls[i];
    }
    //primitive convert
    dst.mode = src.mode;
    //primitive convert
    dst.flags = src.flags;
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_hako_mavlink_msgs_HakoHilActuatorControls_HPP_ */
