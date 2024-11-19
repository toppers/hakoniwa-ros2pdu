#ifndef _PDU_CTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_
#define _PDU_CTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "mavros_msgs/pdu_ctype_GlobalPositionTarget.h"
/*
 * Dependent ros data
 */
#include "mavros_msgs/msg/global_position_target.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_GlobalPositionTarget(const char* heap_ptr, Hako_GlobalPositionTarget &src, mavros_msgs::msg::GlobalPositionTarget &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.coordinate_frame, dst.coordinate_frame);
    // primitive convert
    hako_convert_pdu2ros(src.type_mask, dst.type_mask);
    // primitive convert
    hako_convert_pdu2ros(src.latitude, dst.latitude);
    // primitive convert
    hako_convert_pdu2ros(src.longitude, dst.longitude);
    // primitive convert
    hako_convert_pdu2ros(src.altitude, dst.altitude);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.velocity, dst.velocity);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.acceleration_or_force, dst.acceleration_or_force);
    // primitive convert
    hako_convert_pdu2ros(src.yaw, dst.yaw);
    // primitive convert
    hako_convert_pdu2ros(src.yaw_rate, dst.yaw_rate);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_GlobalPositionTarget(Hako_GlobalPositionTarget &src, mavros_msgs::msg::GlobalPositionTarget &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_GlobalPositionTarget((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_GlobalPositionTarget(mavros_msgs::msg::GlobalPositionTarget &src, Hako_GlobalPositionTarget &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.coordinate_frame, dst.coordinate_frame);
        // primitive convert
        hako_convert_ros2pdu(src.type_mask, dst.type_mask);
        // primitive convert
        hako_convert_ros2pdu(src.latitude, dst.latitude);
        // primitive convert
        hako_convert_ros2pdu(src.longitude, dst.longitude);
        // primitive convert
        hako_convert_ros2pdu(src.altitude, dst.altitude);
        // struct convert
        _ros2pdu_Vector3(src.velocity, dst.velocity, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.acceleration_or_force, dst.acceleration_or_force, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.yaw, dst.yaw);
        // primitive convert
        hako_convert_ros2pdu(src.yaw_rate, dst.yaw_rate);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_GlobalPositionTarget(mavros_msgs::msg::GlobalPositionTarget &src, Hako_GlobalPositionTarget** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_GlobalPositionTarget out;
    if (!_ros2pdu_GlobalPositionTarget(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_GlobalPositionTarget), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_GlobalPositionTarget));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_GlobalPositionTarget*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_GlobalPositionTarget* hako_create_empty_pdu_GlobalPositionTarget(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_GlobalPositionTarget), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_GlobalPositionTarget*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_ */
