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
static inline int _pdu2ros_primitive_array_LaserScan_ranges(const char* varray_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 360; ++i) {
        hako_convert_pdu2ros(src.ranges[i], dst.ranges[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_LaserScan_intensities(const char* varray_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 360; ++i) {
        hako_convert_pdu2ros(src.intensities[i], dst.intensities[i]);
    }
    return 0;
}

static inline int _pdu2ros_LaserScan(const char* varray_ptr, Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    // Struct convert
    _pdu2ros_Header(varray_ptr, src.header, dst.header);
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
    _pdu2ros_primitive_array_LaserScan_ranges(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_LaserScan_intensities(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_LaserScan(Hako_LaserScan &src, sensor_msgs::msg::LaserScan &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LaserScan));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_LaserScan) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_LaserScan(varray_ptr, src, dst);
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
    return true;
}

static inline int hako_convert_ros2pdu_LaserScan(sensor_msgs::msg::LaserScan &src, Hako_LaserScan** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_LaserScan out;
    if (!_ros2pdu_LaserScan(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_LaserScan) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_LaserScan));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LaserScan));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_LaserScan) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_LaserScan*)base_ptr;
    return total_size;
}
static inline Hako_LaserScan* hako_create_empty_pdu_LaserScan(int heap_size)
{
    int total_size = sizeof(Hako_LaserScan) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LaserScan));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_LaserScan) + sizeof(HakoPduMetaDataType);
    return (Hako_LaserScan*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_ */
