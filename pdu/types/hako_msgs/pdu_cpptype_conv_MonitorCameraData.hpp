#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_MonitorCameraData.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_MonitorCameraData.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "sensor_msgs/pdu_cpptype_conv_CompressedImage.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_MonitorCameraData(const char* heap_ptr, Hako_MonitorCameraData &src, HakoCpp_MonitorCameraData &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // primitive convert
    hako_convert_pdu2cpp(src.image_data_length, dst.image_data_length);
    // Struct convert
    cpp_pdu2cpp_CompressedImage(heap_ptr, src.image, dst.image);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_MonitorCameraData(Hako_MonitorCameraData &src, HakoCpp_MonitorCameraData &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_MonitorCameraData((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_MonitorCameraData(HakoCpp_MonitorCameraData &src, Hako_MonitorCameraData &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // primitive convert
        hako_convert_cpp2pdu(src.image_data_length, dst.image_data_length);
        // struct convert
        cpp_cpp2pdu_CompressedImage(src.image, dst.image, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_MonitorCameraData(HakoCpp_MonitorCameraData &src, Hako_MonitorCameraData** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MonitorCameraData out;
    if (!cpp_cpp2pdu_MonitorCameraData(src, out, dynamic_memory)) {
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
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraData_HPP_ */
