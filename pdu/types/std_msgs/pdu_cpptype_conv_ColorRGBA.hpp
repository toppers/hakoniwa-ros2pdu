#ifndef _PDU_CPPTYPE_CONV_HAKO_std_msgs_ColorRGBA_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_std_msgs_ColorRGBA_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_ColorRGBA.h"
/*
 * Dependent cpp pdu data
 */
#include "std_msgs/pdu_cpptype_ColorRGBA.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_ColorRGBA(const char* heap_ptr, Hako_ColorRGBA &src, HakoCpp_ColorRGBA &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.r, dst.r);
    // primitive convert
    hako_convert_pdu2cpp(src.g, dst.g);
    // primitive convert
    hako_convert_pdu2cpp(src.b, dst.b);
    // primitive convert
    hako_convert_pdu2cpp(src.a, dst.a);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ColorRGBA(Hako_ColorRGBA &src, HakoCpp_ColorRGBA &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ColorRGBA((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ColorRGBA(HakoCpp_ColorRGBA &src, Hako_ColorRGBA &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.r, dst.r);
        // primitive convert
        hako_convert_cpp2pdu(src.g, dst.g);
        // primitive convert
        hako_convert_cpp2pdu(src.b, dst.b);
        // primitive convert
        hako_convert_cpp2pdu(src.a, dst.a);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ColorRGBA(HakoCpp_ColorRGBA &src, Hako_ColorRGBA** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ColorRGBA out;
    if (!cpp_cpp2pdu_ColorRGBA(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ColorRGBA), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ColorRGBA));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ColorRGBA*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ColorRGBA* hako_create_empty_pdu_ColorRGBA(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ColorRGBA), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ColorRGBA*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_std_msgs_ColorRGBA_HPP_ */
