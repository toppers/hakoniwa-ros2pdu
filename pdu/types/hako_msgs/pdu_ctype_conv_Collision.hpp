#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_Collision_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_Collision_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_Collision.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/collision.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Collision(Hako_Collision &src,  hako_msgs::msg::Collision &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.collision, dst.collision);
    //primitive convert
    hako_convert_pdu2ros(src.contact_num, dst.contact_num);
    //struct convert
    hako_convert_pdu2ros_Vector3(src.relative_velocity, dst.relative_velocity);
    //struct array convertor
    (void)hako_convert_pdu2ros_array_Point<M_ARRAY_SIZE(Hako_Collision, Hako_Point, contact_position), 10>(
        src.contact_position, dst.contact_position);
    //primitive convert
    hako_convert_pdu2ros(src.restitution_coefficient, dst.restitution_coefficient);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Collision(Hako_Collision src[], std::array<hako_msgs::msg::Collision, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Collision(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Collision(Hako_Collision src[], std::vector<hako_msgs::msg::Collision> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Collision(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Collision(hako_msgs::msg::Collision &src, Hako_Collision &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.collision, dst.collision);
    //primitive convert
    hako_convert_ros2pdu(src.contact_num, dst.contact_num);
    //struct convert
    hako_convert_ros2pdu_Vector3(src.relative_velocity, dst.relative_velocity);
    //struct array convertor
    (void)hako_convert_ros2pdu_array_Point<10, M_ARRAY_SIZE(Hako_Collision, Hako_Point, contact_position)>(
        src.contact_position, dst.contact_position);
    //primitive convert
    hako_convert_ros2pdu(src.restitution_coefficient, dst.restitution_coefficient);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Collision(std::array<hako_msgs::msg::Collision, _src_len> &src, Hako_Collision dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Collision(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Collision(std::vector<hako_msgs::msg::Collision> &src, Hako_Collision dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Collision(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_Collision_HPP_ */
