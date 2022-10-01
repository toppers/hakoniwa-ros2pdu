#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCanBody.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can_body.hpp"

/*
 * Dependent Convertors
 */

static inline int hako_convert_pdu2ros_HakoCanBody(Hako_HakoCanBody &src,  can_msgs::msg::HakoCanBody &dst)
{
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.data, M_ARRAY_SIZE(Hako_HakoCanBody, Hako_uint8, data),
        dst.data, 8);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCanBody(Hako_HakoCanBody src[], std::array<can_msgs::msg::HakoCanBody, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCanBody(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_ */
