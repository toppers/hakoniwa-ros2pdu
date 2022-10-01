#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_color_sensor.hpp"

/*
 * Dependent Convertors
 */

static inline int hako_convert_pdu2ros_Ev3PduColorSensor(Hako_Ev3PduColorSensor &src,  ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.color, dst.color);
    //primitive convert
    hako_convert_pdu2ros(src.reflect, dst.reflect);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_r, dst.rgb_r);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_g, dst.rgb_g);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_b, dst.rgb_b);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduColorSensor(Hako_Ev3PduColorSensor src[], std::array<ev3_msgs::msg::Ev3PduColorSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduColorSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_ */
