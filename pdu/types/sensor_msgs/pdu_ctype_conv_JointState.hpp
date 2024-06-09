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
static inline int _pdu2ros_string_array_JointState_name(const char* varray_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    (void)hako_convert_pdu2ros_array_string<M_ARRAY_SIZE(Hako_JointState, Hako_cstring, name), 2>(
        src.name, dst.name);
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_position(const char* varray_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.position[i], dst.position[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_velocity(const char* varray_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.velocity[i], dst.velocity[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_JointState_effort(const char* varray_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 2; ++i) {
        hako_convert_pdu2ros(src.effort[i], dst.effort[i]);
    }
    return 0;
}

static inline int _pdu2ros_JointState(const char* varray_ptr, Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    // Struct convert
    _pdu2ros_Header(varray_ptr, src.header, dst.header);
    // string array convertor
    _pdu2ros_string_array_JointState_name(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_position(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_velocity(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_JointState_effort(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_JointState(Hako_JointState &src, sensor_msgs::msg::JointState &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_JointState));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_JointState) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_JointState(varray_ptr, src, dst);
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
    return true;
}

static inline int hako_convert_ros2pdu_JointState(sensor_msgs::msg::JointState &src, Hako_JointState** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_JointState out;
    if (!_ros2pdu_JointState(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_JointState) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_JointState));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_JointState));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_JointState) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_JointState*)base_ptr;
    return total_size;
}
static inline Hako_JointState* hako_create_empty_pdu_JointState(int heap_size)
{
    int total_size = sizeof(Hako_JointState) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_JointState));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_JointState) + sizeof(HakoPduMetaDataType);
    return (Hako_JointState*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_ */
