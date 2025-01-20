#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ImpulseCollision.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/impulse_collision.hpp"

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

static inline int _pdu2ros_ImpulseCollision(const char* heap_ptr, Hako_ImpulseCollision &src, hako_msgs::msg::ImpulseCollision &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.collision, dst.collision);
    // primitive convert
    hako_convert_pdu2ros(src.is_target_static, dst.is_target_static);
    // primitive convert
    hako_convert_pdu2ros(src.restitution_coefficient, dst.restitution_coefficient);
    // Struct convert
    _pdu2ros_Point(heap_ptr, src.self_contact_vector, dst.self_contact_vector);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.normal, dst.normal);
    // Struct convert
    _pdu2ros_Point(heap_ptr, src.target_contact_vector, dst.target_contact_vector);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.target_velocity, dst.target_velocity);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.target_angular_velocity, dst.target_angular_velocity);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.target_euler, dst.target_euler);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.target_inertia, dst.target_inertia);
    // primitive convert
    hako_convert_pdu2ros(src.target_mass, dst.target_mass);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_ImpulseCollision(Hako_ImpulseCollision &src, hako_msgs::msg::ImpulseCollision &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_ImpulseCollision((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_ImpulseCollision(hako_msgs::msg::ImpulseCollision &src, Hako_ImpulseCollision &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.collision, dst.collision);
        // primitive convert
        hako_convert_ros2pdu(src.is_target_static, dst.is_target_static);
        // primitive convert
        hako_convert_ros2pdu(src.restitution_coefficient, dst.restitution_coefficient);
        // struct convert
        _ros2pdu_Point(src.self_contact_vector, dst.self_contact_vector, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.normal, dst.normal, dynamic_memory);
        // struct convert
        _ros2pdu_Point(src.target_contact_vector, dst.target_contact_vector, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.target_velocity, dst.target_velocity, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.target_angular_velocity, dst.target_angular_velocity, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.target_euler, dst.target_euler, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.target_inertia, dst.target_inertia, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.target_mass, dst.target_mass);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_ImpulseCollision(hako_msgs::msg::ImpulseCollision &src, Hako_ImpulseCollision** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ImpulseCollision out;
    if (!_ros2pdu_ImpulseCollision(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ImpulseCollision), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ImpulseCollision));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ImpulseCollision*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ImpulseCollision* hako_create_empty_pdu_ImpulseCollision(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ImpulseCollision), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ImpulseCollision*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_ */
