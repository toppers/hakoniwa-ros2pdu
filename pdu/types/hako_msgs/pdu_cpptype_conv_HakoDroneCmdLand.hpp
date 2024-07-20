#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdLand.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_HakoDroneCmdLand.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_cpptype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoDroneCmdLand(const char* heap_ptr, Hako_HakoDroneCmdLand &src, HakoCpp_HakoDroneCmdLand &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoDroneCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2cpp(src.speed, dst.speed);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw_deg, dst.yaw_deg);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoDroneCmdLand(Hako_HakoDroneCmdLand &src, HakoCpp_HakoDroneCmdLand &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoDroneCmdLand((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoDroneCmdLand(HakoCpp_HakoDroneCmdLand &src, Hako_HakoDroneCmdLand &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoDroneCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_cpp2pdu(src.speed, dst.speed);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw_deg, dst.yaw_deg);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoDroneCmdLand(HakoCpp_HakoDroneCmdLand &src, Hako_HakoDroneCmdLand** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoDroneCmdLand out;
    if (!cpp_cpp2pdu_HakoDroneCmdLand(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdLand), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoDroneCmdLand));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoDroneCmdLand*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoDroneCmdLand* hako_create_empty_pdu_HakoDroneCmdLand(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdLand), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoDroneCmdLand*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_ */
