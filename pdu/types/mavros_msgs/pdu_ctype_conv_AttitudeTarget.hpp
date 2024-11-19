#ifndef _PDU_CTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_
#define _PDU_CTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "mavros_msgs/pdu_ctype_AttitudeTarget.h"
/*
 * Dependent ros data
 */
#include "mavros_msgs/msg/attitude_target.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_AttitudeTarget(const char* heap_ptr, Hako_AttitudeTarget &src, mavros_msgs::msg::AttitudeTarget &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.type_mask, dst.type_mask);
    // Struct convert
    _pdu2ros_Quaternion(heap_ptr, src.orientation, dst.orientation);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.body_rate, dst.body_rate);
    // primitive convert
    hako_convert_pdu2ros(src.thrust, dst.thrust);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_AttitudeTarget(Hako_AttitudeTarget &src, mavros_msgs::msg::AttitudeTarget &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_AttitudeTarget((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_AttitudeTarget(mavros_msgs::msg::AttitudeTarget &src, Hako_AttitudeTarget &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.type_mask, dst.type_mask);
        // struct convert
        _ros2pdu_Quaternion(src.orientation, dst.orientation, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.body_rate, dst.body_rate, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.thrust, dst.thrust);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_AttitudeTarget(mavros_msgs::msg::AttitudeTarget &src, Hako_AttitudeTarget** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_AttitudeTarget out;
    if (!_ros2pdu_AttitudeTarget(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_AttitudeTarget), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_AttitudeTarget));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_AttitudeTarget*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_AttitudeTarget* hako_create_empty_pdu_AttitudeTarget(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_AttitudeTarget), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_AttitudeTarget*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_ */
