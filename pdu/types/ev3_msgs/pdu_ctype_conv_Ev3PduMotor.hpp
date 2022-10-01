#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduMotor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_motor.hpp"

/*
 * Dependent Convertors
 */

static inline int hako_convert_pdu2ros_Ev3PduMotor(Hako_Ev3PduMotor &src,  ev3_msgs::msg::Ev3PduMotor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.power, dst.power);
    //primitive convert
    hako_convert_pdu2ros(src.stop, dst.stop);
    //primitive convert
    hako_convert_pdu2ros(src.reset_angle, dst.reset_angle);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduMotor(Hako_Ev3PduMotor src[], std::array<ev3_msgs::msg::Ev3PduMotor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduMotor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_ */
