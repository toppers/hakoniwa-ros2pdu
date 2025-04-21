#ifndef _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"
/*
 * Dependent ros data
 */
#include "hako_srv_msgs/msg/service_response_header.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_ServiceResponseHeader(const char* heap_ptr, Hako_ServiceResponseHeader &src, hako_srv_msgs::msg::ServiceResponseHeader &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    // string convertor
    dst.service_name = (const char*)src.service_name;
    // string convertor
    dst.client_name = (const char*)src.client_name;
    // primitive convert
    hako_convert_pdu2ros(src.status, dst.status);
    // primitive convert
    hako_convert_pdu2ros(src.processing_percentage, dst.processing_percentage);
    // primitive convert
    hako_convert_pdu2ros(src.result_code, dst.result_code);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_ServiceResponseHeader(Hako_ServiceResponseHeader &src, hako_srv_msgs::msg::ServiceResponseHeader &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_ServiceResponseHeader((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_ServiceResponseHeader(hako_srv_msgs::msg::ServiceResponseHeader &src, Hako_ServiceResponseHeader &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.request_id, dst.request_id);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.service_name, src.service_name.length(),
            dst.service_name, M_ARRAY_SIZE(Hako_ServiceResponseHeader, char, service_name));
        dst.service_name[src.service_name.length()] = '\0';
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.client_name, src.client_name.length(),
            dst.client_name, M_ARRAY_SIZE(Hako_ServiceResponseHeader, char, client_name));
        dst.client_name[src.client_name.length()] = '\0';
        // primitive convert
        hako_convert_ros2pdu(src.status, dst.status);
        // primitive convert
        hako_convert_ros2pdu(src.processing_percentage, dst.processing_percentage);
        // primitive convert
        hako_convert_ros2pdu(src.result_code, dst.result_code);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_ServiceResponseHeader(hako_srv_msgs::msg::ServiceResponseHeader &src, Hako_ServiceResponseHeader** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ServiceResponseHeader out;
    if (!_ros2pdu_ServiceResponseHeader(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ServiceResponseHeader), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ServiceResponseHeader));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ServiceResponseHeader*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ServiceResponseHeader* hako_create_empty_pdu_ServiceResponseHeader(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ServiceResponseHeader), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ServiceResponseHeader*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_ */
