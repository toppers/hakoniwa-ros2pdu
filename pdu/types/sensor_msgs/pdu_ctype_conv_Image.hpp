#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_Image.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/image.hpp"

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
static inline int _pdu2ros_primitive_array_Image_data(const char* heap_ptr, Hako_Image &src, sensor_msgs::msg::Image &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 1024000; ++i) {
        hako_convert_pdu2ros(src.data[i], dst.data[i]);
    }
    return 0;
}

static inline int _pdu2ros_Image(const char* heap_ptr, Hako_Image &src, sensor_msgs::msg::Image &dst)
{
    // Struct convert
    _pdu2ros_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // string convertor
    dst.encoding = (const char*)src.encoding;
    // primitive convert
    hako_convert_pdu2ros(src.is_bigendian, dst.is_bigendian);
    // primitive convert
    hako_convert_pdu2ros(src.step, dst.step);
    // primitive array convertor
    _pdu2ros_primitive_array_Image_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Image(Hako_Image &src, sensor_msgs::msg::Image &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Image((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_Image_data(sensor_msgs::msg::Image &src, Hako_Image &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 1024000
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_Image, Hako_uint8, data));
    return true;
}

static inline bool _ros2pdu_Image(sensor_msgs::msg::Image &src, Hako_Image &dst, PduDynamicMemory &dynamic_memory)
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
            src.encoding, src.encoding.length(),
            dst.encoding, M_ARRAY_SIZE(Hako_Image, char, encoding));
        // primitive convert
        hako_convert_ros2pdu(src.is_bigendian, dst.is_bigendian);
        // primitive convert
        hako_convert_ros2pdu(src.step, dst.step);
        //primitive array copy
        _ros2pdu_primitive_array_Image_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Image(sensor_msgs::msg::Image &src, Hako_Image** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Image out;
    if (!_ros2pdu_Image(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Image), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Image));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Image*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Image* hako_create_empty_pdu_Image(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Image), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Image*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_ */
