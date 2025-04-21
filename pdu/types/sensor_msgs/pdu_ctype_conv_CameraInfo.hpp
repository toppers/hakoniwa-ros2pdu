#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_CameraInfo.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/camera_info.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_RegionOfInterest.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_CameraInfo_d(const char* heap_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Convert using len and off
    int offset = src._d_off;
    int length = src._d_len;
    if (length > 0) {
        dst.d.resize(length);
        memcpy(dst.d.data(), heap_ptr + offset, length * sizeof(Hako_float64));
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_k(const char* heap_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.k[i], dst.k[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_r(const char* heap_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.r[i], dst.r[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_p(const char* heap_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 12; ++i) {
        hako_convert_pdu2ros(src.p[i], dst.p[i]);
    }
    return 0;
}

static inline int _pdu2ros_CameraInfo(const char* heap_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // string convertor
    dst.distortion_model = (const char*)src.distortion_model;
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_d(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_k(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_r(heap_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_p(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.binning_x, dst.binning_x);
    // primitive convert
    hako_convert_pdu2ros(src.binning_y, dst.binning_y);
    // Struct convert
    _pdu2ros_RegionOfInterest(heap_ptr, src.roi, dst.roi);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_CameraInfo(Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_CameraInfo((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_CameraInfo_d(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._d_len = src.d.size();
    if (dst._d_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._d_len, sizeof(Hako_float64));
        memcpy(temp_ptr, src.d.data(), dst._d_len * sizeof(Hako_float64));
        dst._d_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._d_off = dynamic_memory.get_total_size();
    }
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_k(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.k, src.k.size(),
        dst.k, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, k));
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_r(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.r, src.r.size(),
        dst.r, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, r));
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_p(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 12
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.p, src.p.size(),
        dst.p, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, p));
    return true;
}

static inline bool _ros2pdu_CameraInfo(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.width, dst.width);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.distortion_model, src.distortion_model.length(),
            dst.distortion_model, M_ARRAY_SIZE(Hako_CameraInfo, char, distortion_model));
        dst.distortion_model[src.distortion_model.length()] = '\0';
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_d(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_k(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_r(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_p(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.binning_x, dst.binning_x);
        // primitive convert
        hako_convert_ros2pdu(src.binning_y, dst.binning_y);
        // struct convert
        _ros2pdu_RegionOfInterest(src.roi, dst.roi, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_CameraInfo(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_CameraInfo out;
    if (!_ros2pdu_CameraInfo(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_CameraInfo), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_CameraInfo));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_CameraInfo*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_CameraInfo* hako_create_empty_pdu_CameraInfo(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_CameraInfo), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_CameraInfo*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_ */
