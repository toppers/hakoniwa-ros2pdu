#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCanHead.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can_head.hpp"

/*
 * Dependent Convertors
 */

static inline int hako_convert_pdu2ros_HakoCanHead(Hako_HakoCanHead &src,  can_msgs::msg::HakoCanHead &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.channel, dst.channel);
    //primitive convert
    hako_convert_pdu2ros(src.ide, dst.ide);
    //primitive convert
    hako_convert_pdu2ros(src.rtr, dst.rtr);
    //primitive convert
    hako_convert_pdu2ros(src.dlc, dst.dlc);
    //primitive convert
    hako_convert_pdu2ros(src.canid, dst.canid);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCanHead(Hako_HakoCanHead src[], std::array<can_msgs::msg::HakoCanHead, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCanHead(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_ */
