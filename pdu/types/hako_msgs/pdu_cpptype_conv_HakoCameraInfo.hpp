#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCameraInfo_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCameraInfo.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_HakoCameraInfo.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoCameraInfo(const char* heap_ptr, Hako_HakoCameraInfo &src, HakoCpp_HakoCameraInfo &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.angle, dst.angle);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoCameraInfo(Hako_HakoCameraInfo &src, HakoCpp_HakoCameraInfo &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoCameraInfo((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoCameraInfo(HakoCpp_HakoCameraInfo &src, Hako_HakoCameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // struct convert
        cpp_cpp2pdu_Vector3(src.angle, dst.angle, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoCameraInfo(HakoCpp_HakoCameraInfo &src, Hako_HakoCameraInfo** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCameraInfo out;
    if (!cpp_cpp2pdu_HakoCameraInfo(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCameraInfo), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCameraInfo));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCameraInfo*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCameraInfo* hako_create_empty_pdu_HakoCameraInfo(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCameraInfo), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCameraInfo*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCameraInfo_HPP_ */
