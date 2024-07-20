#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_GameControllerOperation.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_GameControllerOperation.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_GameControllerOperation_axis(const char* heap_ptr, Hako_GameControllerOperation &src, HakoCpp_GameControllerOperation &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 6; ++i) {
        hako_convert_pdu2cpp(src.axis[i], dst.axis[i]);
    }
    return 0;
}
static inline int cpp_pdu2cpp_primitive_array_GameControllerOperation_button(const char* heap_ptr, Hako_GameControllerOperation &src, HakoCpp_GameControllerOperation &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 15; ++i) {
        hako_convert_pdu2cpp(src.button[i], dst.button[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_GameControllerOperation(const char* heap_ptr, Hako_GameControllerOperation &src, HakoCpp_GameControllerOperation &dst)
{
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_GameControllerOperation_axis(heap_ptr, src, dst);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_GameControllerOperation_button(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_GameControllerOperation(Hako_GameControllerOperation &src, HakoCpp_GameControllerOperation &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_GameControllerOperation((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_GameControllerOperation_axis(HakoCpp_GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 6
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.axis, src.axis.size(),
        dst.axis, M_ARRAY_SIZE(Hako_GameControllerOperation, Hako_float64, axis));
    return true;
}
static inline bool cpp_cpp2pdu_primitive_array_GameControllerOperation_button(HakoCpp_GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 15
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.button, src.button.size(),
        dst.button, M_ARRAY_SIZE(Hako_GameControllerOperation, Hako_bool, button));
    return true;
}

static inline bool cpp_cpp2pdu_GameControllerOperation(HakoCpp_GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //primitive array copy
        cpp_cpp2pdu_primitive_array_GameControllerOperation_axis(src, dst, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_GameControllerOperation_button(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_GameControllerOperation(HakoCpp_GameControllerOperation &src, Hako_GameControllerOperation** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_GameControllerOperation out;
    if (!cpp_cpp2pdu_GameControllerOperation(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_GameControllerOperation), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_GameControllerOperation));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_GameControllerOperation*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_GameControllerOperation* hako_create_empty_pdu_GameControllerOperation(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_GameControllerOperation), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_GameControllerOperation*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_ */
