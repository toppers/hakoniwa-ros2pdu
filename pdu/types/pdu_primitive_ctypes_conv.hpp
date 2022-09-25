#ifndef _PDU_PRIMITIVE_CTYPES_CONV_HPP_
#define _PDU_PRIMITIVE_CTYPES_CONV_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"

template <class PduPrimitiveType, class RosPrimitiveType> 
void hako_convert_pdu2ros(PduPrimitiveType &src, RosPrimitiveType &dst)
{
    dst = src;
    return;
}

template <class RosPrimitiveType, class PduPrimitiveType> 
void hako_convert_ros2pdu(RosPrimitiveType &src, PduPrimitiveType &dst)
{
    dst = src;
    return;
}

#endif /* _PDU_PRIMITIVE_CTYPES_CONV_HPP_ */