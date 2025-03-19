#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_MonitorCameraData.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/monitor_camera_data.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_CompressedImage.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_MonitorCameraData(const char* heap_ptr, Hako_MonitorCameraData &src, hako_msgs::msg::MonitorCameraData &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    // primitive convert
    hako_convert_pdu2ros(src.image_data_length, dst.image_data_length);
    // Struct convert
    _pdu2ros_CompressedImage(heap_ptr, src.image, dst.image);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_MonitorCameraData(Hako_MonitorCameraData &src, hako_msgs::msg::MonitorCameraData &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_MonitorCameraData((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_MonitorCameraData(hako_msgs::msg::MonitorCameraData &src, Hako_MonitorCameraData &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.request_id, dst.request_id);
        // primitive convert
        hako_convert_ros2pdu(src.image_data_length, dst.image_data_length);
        // struct convert
        _ros2pdu_CompressedImage(src.image, dst.image, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_MonitorCameraData(hako_msgs::msg::MonitorCameraData &src, Hako_MonitorCameraData** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MonitorCameraData out;
    if (!_ros2pdu_MonitorCameraData(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MonitorCameraData), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MonitorCameraData));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MonitorCameraData*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MonitorCameraData* hako_create_empty_pdu_MonitorCameraData(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MonitorCameraData), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MonitorCameraData*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_ */
