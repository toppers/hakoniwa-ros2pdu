#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ManualPosAttControl.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_ManualPosAttControl.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_ManualPosAttControl(const char* heap_ptr, Hako_ManualPosAttControl &src, HakoCpp_ManualPosAttControl &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.do_operation, dst.do_operation);
    // Struct convert
    cpp_pdu2cpp_Twist(heap_ptr, src.posatt, dst.posatt);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ManualPosAttControl(Hako_ManualPosAttControl &src, HakoCpp_ManualPosAttControl &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ManualPosAttControl((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ManualPosAttControl(HakoCpp_ManualPosAttControl &src, Hako_ManualPosAttControl &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.do_operation, dst.do_operation);
        // struct convert
        cpp_cpp2pdu_Twist(src.posatt, dst.posatt, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ManualPosAttControl(HakoCpp_ManualPosAttControl &src, Hako_ManualPosAttControl** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ManualPosAttControl out;
    if (!cpp_cpp2pdu_ManualPosAttControl(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ManualPosAttControl), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ManualPosAttControl));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ManualPosAttControl*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ManualPosAttControl* hako_create_empty_pdu_ManualPosAttControl(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ManualPosAttControl), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ManualPosAttControl*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_ */
