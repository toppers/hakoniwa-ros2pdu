#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCan.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can.hpp"

/*
 * Dependent Convertors
 */
#include "pdu_ctype_conv_HakoCanBody.hpp"
#include "pdu_ctype_conv_HakoCanHead.hpp"

static inline int hako_convert_pdu2ros_HakoCan(Hako_HakoCan &src,  can_msgs::msg::HakoCan &dst)
{
    //struct convert
    hako_convert_pdu2ros_HakoCanHead(src.head, dst.head);
    //struct convert
    hako_convert_pdu2ros_HakoCanBody(src.body, dst.body);
    return 0;
}


template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCan(Hako_HakoCan src[], std::array<can_msgs::msg::HakoCan, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCan(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_ */
