#ifndef _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_
#define _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "nav_msgs/pdu_ctype_Odometry.h"
/*
 * Dependent ros data
 */
#include "nav_msgs/msg/odometry.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_PoseWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_TwistWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Odometry(const char* heap_ptr, Hako_Odometry &src, nav_msgs::msg::Odometry &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    // Struct convert
    _pdu2ros_PoseWithCovariance(heap_ptr, src.pose, dst.pose);
    // Struct convert
    _pdu2ros_TwistWithCovariance(heap_ptr, src.twist, dst.twist);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Odometry(Hako_Odometry &src, nav_msgs::msg::Odometry &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Odometry((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Odometry(nav_msgs::msg::Odometry &src, Hako_Odometry &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.child_frame_id, src.child_frame_id.length(),
            dst.child_frame_id, M_ARRAY_SIZE(Hako_Odometry, char, child_frame_id));
        dst.child_frame_id[src.child_frame_id.length()] = '\0';
        // struct convert
        _ros2pdu_PoseWithCovariance(src.pose, dst.pose, dynamic_memory);
        // struct convert
        _ros2pdu_TwistWithCovariance(src.twist, dst.twist, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Odometry(nav_msgs::msg::Odometry &src, Hako_Odometry** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Odometry out;
    if (!_ros2pdu_Odometry(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Odometry), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Odometry));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Odometry*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Odometry* hako_create_empty_pdu_Odometry(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Odometry), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Odometry*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_ */
