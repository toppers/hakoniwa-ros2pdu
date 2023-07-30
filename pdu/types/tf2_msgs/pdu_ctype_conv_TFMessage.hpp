#ifndef _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_
#define _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "tf2_msgs/pdu_ctype_TFMessage.h"
/*
 * Dependent ros data
 */
#include "tf2_msgs/msg/tf_message.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Transform.hpp"
#include "geometry_msgs/pdu_ctype_conv_TransformStamped.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_TFMessage(Hako_TFMessage &src,  tf2_msgs::msg::TFMessage &dst)
{
    //struct array convertor
    (void)hako_convert_pdu2ros_array_TransformStamped<M_ARRAY_SIZE(Hako_TFMessage, Hako_TransformStamped, transforms), 1>(
        src.transforms, dst.transforms);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_TFMessage(Hako_TFMessage src[], std::array<tf2_msgs::msg::TFMessage, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_TFMessage(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_TFMessage(Hako_TFMessage src[], std::vector<tf2_msgs::msg::TFMessage> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_TFMessage(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_TFMessage(tf2_msgs::msg::TFMessage &src, Hako_TFMessage &dst)
{
    //struct array convertor
    (void)hako_convert_ros2pdu_array_TransformStamped<1, M_ARRAY_SIZE(Hako_TFMessage, Hako_TransformStamped, transforms)>(
        src.transforms, dst.transforms);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_TFMessage(std::array<tf2_msgs::msg::TFMessage, _src_len> &src, Hako_TFMessage dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_TFMessage(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_TFMessage(std::vector<tf2_msgs::msg::TFMessage> &src, Hako_TFMessage dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_TFMessage(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_ */
