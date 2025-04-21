#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_CompressedImage.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/compressed_image.hpp"

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
static inline int _pdu2ros_primitive_array_CompressedImage_data(const char* heap_ptr, Hako_CompressedImage &src, sensor_msgs::msg::CompressedImage &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_uint8));
    }
    return 0;
}

static inline int _pdu2ros_CompressedImage(const char* heap_ptr, Hako_CompressedImage &src, sensor_msgs::msg::CompressedImage &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // string convertor
    dst.format = (const char*)src.format;
    // primitive array convertor
    _pdu2ros_primitive_array_CompressedImage_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_CompressedImage(Hako_CompressedImage &src, sensor_msgs::msg::CompressedImage &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_CompressedImage((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_CompressedImage_data(sensor_msgs::msg::CompressedImage &src, Hako_CompressedImage &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_uint8));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_uint8));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool _ros2pdu_CompressedImage(sensor_msgs::msg::CompressedImage &src, Hako_CompressedImage &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.format, src.format.length(),
            dst.format, M_ARRAY_SIZE(Hako_CompressedImage, char, format));
        dst.format[src.format.length()] = '\0';
        //primitive array copy
        _ros2pdu_primitive_array_CompressedImage_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_CompressedImage(sensor_msgs::msg::CompressedImage &src, Hako_CompressedImage** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_CompressedImage out;
    if (!_ros2pdu_CompressedImage(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_CompressedImage), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_CompressedImage));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_CompressedImage*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_CompressedImage* hako_create_empty_pdu_CompressedImage(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_CompressedImage), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_CompressedImage*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_ */
