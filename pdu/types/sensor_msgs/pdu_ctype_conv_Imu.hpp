#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_Imu.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/imu.hpp"

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
static inline int _pdu2ros_primitive_array_Imu_orientation_covariance(const char* heap_ptr, Hako_Imu &src, sensor_msgs::msg::Imu &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.orientation_covariance[i], dst.orientation_covariance[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_Imu_angular_velocity_covariance(const char* heap_ptr, Hako_Imu &src, sensor_msgs::msg::Imu &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.angular_velocity_covariance[i], dst.angular_velocity_covariance[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_Imu_linear_acceleration_covariance(const char* heap_ptr, Hako_Imu &src, sensor_msgs::msg::Imu &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.linear_acceleration_covariance[i], dst.linear_acceleration_covariance[i]);
    }
    return 0;
}

static inline int _pdu2ros_Imu(const char* heap_ptr, Hako_Imu &src, sensor_msgs::msg::Imu &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // Struct convert
    _pdu2ros_Quaternion(heap_ptr, src.orientation, dst.orientation);
    // primitive array convertor
    _pdu2ros_primitive_array_Imu_orientation_covariance(heap_ptr, src, dst);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.angular_velocity, dst.angular_velocity);
    // primitive array convertor
    _pdu2ros_primitive_array_Imu_angular_velocity_covariance(heap_ptr, src, dst);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.linear_acceleration, dst.linear_acceleration);
    // primitive array convertor
    _pdu2ros_primitive_array_Imu_linear_acceleration_covariance(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Imu(Hako_Imu &src, sensor_msgs::msg::Imu &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Imu((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_Imu_orientation_covariance(sensor_msgs::msg::Imu &src, Hako_Imu &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.orientation_covariance, src.orientation_covariance.size(),
        dst.orientation_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, orientation_covariance));
    return true;
}
static inline bool _ros2pdu_primitive_array_Imu_angular_velocity_covariance(sensor_msgs::msg::Imu &src, Hako_Imu &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.angular_velocity_covariance, src.angular_velocity_covariance.size(),
        dst.angular_velocity_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, angular_velocity_covariance));
    return true;
}
static inline bool _ros2pdu_primitive_array_Imu_linear_acceleration_covariance(sensor_msgs::msg::Imu &src, Hako_Imu &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.linear_acceleration_covariance, src.linear_acceleration_covariance.size(),
        dst.linear_acceleration_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, linear_acceleration_covariance));
    return true;
}

static inline bool _ros2pdu_Imu(sensor_msgs::msg::Imu &src, Hako_Imu &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // struct convert
        _ros2pdu_Quaternion(src.orientation, dst.orientation, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Imu_orientation_covariance(src, dst, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.angular_velocity, dst.angular_velocity, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Imu_angular_velocity_covariance(src, dst, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.linear_acceleration, dst.linear_acceleration, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Imu_linear_acceleration_covariance(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Imu(sensor_msgs::msg::Imu &src, Hako_Imu** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Imu out;
    if (!_ros2pdu_Imu(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Imu), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Imu));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Imu*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Imu* hako_create_empty_pdu_Imu(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Imu), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Imu*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_ */
