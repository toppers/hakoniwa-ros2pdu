#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensorHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensorHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduSensorHeader.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_sensor_header.hpp"

/*
 * Dependent Convertors
 */

static inline int hako_convert_pdu2ros_Ev3PduSensorHeader(Hako_Ev3PduSensorHeader &src,  ev3_msgs::msg::Ev3PduSensorHeader &dst)
{
    //string convertor
#if 0 /* for ros2pdu */
    (void)hako_convert_pdu2ros_array(
        src.name, M_ARRAY_SIZE(Hako_Ev3PduSensorHeader, char, name),
        dst.name, dst.name.length());
#endif
    dst.name = (const char*)src.name;
    //primitive convert
    hako_convert_pdu2ros(src.version, dst.version);
    //primitive convert
    hako_convert_pdu2ros(src.hakoniwa_time, dst.hakoniwa_time);
    //primitive convert
    hako_convert_pdu2ros(src.ext_off, dst.ext_off);
    //primitive convert
    hako_convert_pdu2ros(src.ext_size, dst.ext_size);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduSensorHeader(Hako_Ev3PduSensorHeader src[], std::array<ev3_msgs::msg::Ev3PduSensorHeader, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduSensorHeader(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensorHeader_HPP_ */
