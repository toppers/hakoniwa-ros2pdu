#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_ServiceResponseHeader(const char* heap_ptr, Hako_ServiceResponseHeader &src, HakoCpp_ServiceResponseHeader &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // string convertor
    dst.service_name = (const char*)src.service_name;
    // string convertor
    dst.client_name = (const char*)src.client_name;
    // primitive convert
    hako_convert_pdu2cpp(src.processing_percentage, dst.processing_percentage);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ServiceResponseHeader(Hako_ServiceResponseHeader &src, HakoCpp_ServiceResponseHeader &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ServiceResponseHeader((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ServiceResponseHeader(HakoCpp_ServiceResponseHeader &src, Hako_ServiceResponseHeader &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.service_name, src.service_name.length(),
            dst.service_name, M_ARRAY_SIZE(Hako_ServiceResponseHeader, char, service_name));
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.client_name, src.client_name.length(),
            dst.client_name, M_ARRAY_SIZE(Hako_ServiceResponseHeader, char, client_name));
        // primitive convert
        hako_convert_cpp2pdu(src.processing_percentage, dst.processing_percentage);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ServiceResponseHeader(HakoCpp_ServiceResponseHeader &src, Hako_ServiceResponseHeader** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ServiceResponseHeader out;
    if (!cpp_cpp2pdu_ServiceResponseHeader(src, out, dynamic_memory)) {
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
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceResponseHeader_HPP_ */
