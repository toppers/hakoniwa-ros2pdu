#ifndef _PDU_PRIMITIVE_CTYPES_CONV_HPP_
#define _PDU_PRIMITIVE_CTYPES_CONV_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include <string>

template <class PduPrimitiveType, class RosPrimitiveType> 
void hako_convert_pdu2ros(PduPrimitiveType &src, RosPrimitiveType &dst)
{
    dst = src;
    return;
}
template <class PduPrimitiveType, class RosPrimitiveType> 
int hako_convert_pdu2ros_array(PduPrimitiveType src[], int src_len, RosPrimitiveType &dst, int dst_len)
{
    int ret = 0;
    int len = dst_len;
    if (dst_len < src_len) {
        dst_len = src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    return ret;
}

template <class RosPrimitiveType, class PduPrimitiveType> 
void hako_convert_ros2pdu(RosPrimitiveType &src, PduPrimitiveType &dst)
{
    dst = src;
    return;
}
template <class RosPrimitiveType, class PduPrimitiveType> 
int hako_convert_ros2pdu_array(RosPrimitiveType &src, int src_len, PduPrimitiveType &dst, int dst_len)
{
    int ret = 0;
    int len = dst_len;
    if (dst_len < src_len) {
        dst_len = src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    return ret;
}

#endif /* _PDU_PRIMITIVE_CTYPES_CONV_HPP_ */