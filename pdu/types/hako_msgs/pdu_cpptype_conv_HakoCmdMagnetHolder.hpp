#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdMagnetHolder.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_HakoCmdMagnetHolder.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_cpptype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoCmdMagnetHolder(const char* heap_ptr, Hako_HakoCmdMagnetHolder &src, HakoCpp_HakoCmdMagnetHolder &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.magnet_on, dst.magnet_on);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoCmdMagnetHolder(Hako_HakoCmdMagnetHolder &src, HakoCpp_HakoCmdMagnetHolder &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoCmdMagnetHolder((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoCmdMagnetHolder(HakoCpp_HakoCmdMagnetHolder &src, Hako_HakoCmdMagnetHolder &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.magnet_on, dst.magnet_on);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoCmdMagnetHolder(HakoCpp_HakoCmdMagnetHolder &src, Hako_HakoCmdMagnetHolder** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCmdMagnetHolder out;
    if (!cpp_cpp2pdu_HakoCmdMagnetHolder(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCmdMagnetHolder), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCmdMagnetHolder));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCmdMagnetHolder*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCmdMagnetHolder* hako_create_empty_pdu_HakoCmdMagnetHolder(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCmdMagnetHolder), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCmdMagnetHolder*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_ */
