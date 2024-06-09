#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_LaserScan.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/laser_scan.hpp"

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
static inline int _pdu2ros_primitive_array_LaserScan_ranges(const char* heap_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 360; ++i) {
        hako_convert_pdu2ros(src.ranges[i], dst.ranges[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_LaserScan_intensities(const char* heap_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 360; ++i) {
        hako_convert_pdu2ros(src.intensities[i], dst.intensities[i]);
    }
    return 0;
}

static inline int _pdu2ros_LaserScan(const char* heap_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.angle_min, dst.angle_min);
    // primitive convert
    hako_convert_pdu2ros(src.angle_max, dst.angle_max);
    // primitive convert
    hako_convert_pdu2ros(src.angle_increment, dst.angle_increment);
    // primitive convert
    hako_convert_pdu2ros(src.time_increment, dst.time_increment);
    // primitive convert
    hako_convert_pdu2ros(src.scan_time, dst.scan_time);
    // primitive convert
    hako_convert_pdu2ros(src.range_min, dst.range_min);
    // primitive convert
    hako_convert_pdu2ros(src.range_max, dst.range_max);
    // primitive array convertor
    _pdu2ros_primitive_array_LaserScan_ranges(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_LaserScan_intensities(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_LaserScan(Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_LaserScan((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_LaserScan_ranges(sensor_msgs::msg::LaserScan &src, Hako_LaserScan &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 360
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.ranges, src.ranges.size(),
        dst.ranges, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, ranges));
    return true;
}
static inline bool _ros2pdu_primitive_array_LaserScan_intensities(sensor_msgs::msg::LaserScan &src, Hako_LaserScan &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 360
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.intensities, src.intensities.size(),
        dst.intensities, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, intensities));
    return true;
}

static inline bool _ros2pdu_LaserScan(sensor_msgs::msg::LaserScan &src, Hako_LaserScan &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.angle_min, dst.angle_min);
        // primitive convert
        hako_convert_ros2pdu(src.angle_max, dst.angle_max);
        // primitive convert
        hako_convert_ros2pdu(src.angle_increment, dst.angle_increment);
        // primitive convert
        hako_convert_ros2pdu(src.time_increment, dst.time_increment);
        // primitive convert
        hako_convert_ros2pdu(src.scan_time, dst.scan_time);
        // primitive convert
        hako_convert_ros2pdu(src.range_min, dst.range_min);
        // primitive convert
        hako_convert_ros2pdu(src.range_max, dst.range_max);
        //primitive array copy
        _ros2pdu_primitive_array_LaserScan_ranges(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_LaserScan_intensities(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_LaserScan(sensor_msgs::msg::LaserScan &src, Hako_LaserScan** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_LaserScan out;
    if (!_ros2pdu_LaserScan(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_LaserScan), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_LaserScan));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_LaserScan*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_LaserScan* hako_create_empty_pdu_LaserScan(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_LaserScan), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_LaserScan*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_ */
