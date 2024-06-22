#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/point_cloud2.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_PointField.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
 #define PDU2ROS_RESIZE_ARRAY()
static inline int _pdu2ros_struct_array_PointCloud2_fields(const char* heap_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 4; ++i) {
        _pdu2ros_PointField(heap_ptr, src.fields[i], dst.fields[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_PointCloud2_data(const char* heap_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 176656; ++i) {
        hako_convert_pdu2ros(src.data[i], dst.data[i]);
    }
    return 0;
}

static inline int _pdu2ros_PointCloud2(const char* heap_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // struct array convertor
    _pdu2ros_struct_array_PointCloud2_fields(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.is_bigendian, dst.is_bigendian);
    // primitive convert
    hako_convert_pdu2ros(src.point_step, dst.point_step);
    // primitive convert
    hako_convert_pdu2ros(src.row_step, dst.row_step);
    // primitive array convertor
    _pdu2ros_primitive_array_PointCloud2_data(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.is_dense, dst.is_dense);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_PointCloud2(Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_PointCloud2((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_struct_array_PointCloud2_fields(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 4; ++i) {
        _ros2pdu_PointField(src.fields[i], dst.fields[i], dynamic_memory);
    }
    return true;
}
static inline bool _ros2pdu_primitive_array_PointCloud2_data(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 176656
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_PointCloud2, Hako_uint8, data));
    return true;
}

static inline bool _ros2pdu_PointCloud2(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.width, dst.width);
        //struct array convert
        _ros2pdu_struct_array_PointCloud2_fields(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.is_bigendian, dst.is_bigendian);
        // primitive convert
        hako_convert_ros2pdu(src.point_step, dst.point_step);
        // primitive convert
        hako_convert_ros2pdu(src.row_step, dst.row_step);
        //primitive array copy
        _ros2pdu_primitive_array_PointCloud2_data(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.is_dense, dst.is_dense);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_PointCloud2(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PointCloud2 out;
    if (!_ros2pdu_PointCloud2(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_PointCloud2), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PointCloud2));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_PointCloud2*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_PointCloud2* hako_create_empty_pdu_PointCloud2(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_PointCloud2), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_PointCloud2*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_ */
