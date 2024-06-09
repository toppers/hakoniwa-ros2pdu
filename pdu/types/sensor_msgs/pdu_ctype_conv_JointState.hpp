#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_JointState.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/joint_state.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_string_array_JointState_name(const char* heap_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    (void)hako_convert_pdu2ros_array_string<M_ARRAY_SIZE(Hako_JointState, Hako_cstring, name), 2>(
        src.name, dst.name);
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_position(const char* heap_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.position[i], dst.position[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_velocity(const char* heap_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.velocity[i], dst.velocity[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_effort(const char* heap_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.effort[i], dst.effort[i]);
    }
    return 0;
}

static inline int _pdu2ros_JointState(const char* heap_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // string array convertor
    _pdu2ros_string_array_JointState_name(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_position(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_velocity(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_effort(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_JointState(Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_JointState((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_string_array_JointState_name(sensor_msgs::msg::JointState &src, Hako_JointState &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed string 2
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array_string<2, M_ARRAY_SIZE(Hako_JointState, Hako_cstring, name)>(
        src.name, dst.name);
    return true;
}
static inline bool _ros2pdu_primitive_array_JointState_position(sensor_msgs::msg::JointState &src, Hako_JointState &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 2
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.position, src.position.size(),
        dst.position, M_ARRAY_SIZE(Hako_JointState, Hako_float64, position));
    return true;
}
static inline bool _ros2pdu_primitive_array_JointState_velocity(sensor_msgs::msg::JointState &src, Hako_JointState &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 2
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.velocity, src.velocity.size(),
        dst.velocity, M_ARRAY_SIZE(Hako_JointState, Hako_float64, velocity));
    return true;
}
static inline bool _ros2pdu_primitive_array_JointState_effort(sensor_msgs::msg::JointState &src, Hako_JointState &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 2
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.effort, src.effort.size(),
        dst.effort, M_ARRAY_SIZE(Hako_JointState, Hako_float64, effort));
    return true;
}

static inline bool _ros2pdu_JointState(sensor_msgs::msg::JointState &src, Hako_JointState &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // string array convert
        _ros2pdu_string_array_JointState_name(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_JointState_position(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_JointState_velocity(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_JointState_effort(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_JointState(sensor_msgs::msg::JointState &src, Hako_JointState** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_JointState out;
    if (!_ros2pdu_JointState(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_JointState), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_JointState));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_JointState*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_JointState* hako_create_empty_pdu_JointState(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_JointState), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_JointState*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_ */
