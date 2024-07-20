#ifndef _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int8MultiArray_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int8MultiArray_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_Int8MultiArray.h"
/*
 * Dependent cpp pdu data
 */
#include "std_msgs/pdu_cpptype_Int8MultiArray.hpp"

/*
 * Dependent Convertors
 */
#include "std_msgs/pdu_cpptype_conv_MultiArrayDimension.hpp"
#include "std_msgs/pdu_cpptype_conv_MultiArrayLayout.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_Int8MultiArray_data(const char* heap_ptr, Hako_Int8MultiArray &src, HakoCpp_Int8MultiArray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_int8));
    }
    return 0;
}

static inline int cpp_pdu2cpp_Int8MultiArray(const char* heap_ptr, Hako_Int8MultiArray &src, HakoCpp_Int8MultiArray &dst)
{
    // Struct convert
    cpp_pdu2cpp_MultiArrayLayout(heap_ptr, src.layout, dst.layout);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_Int8MultiArray_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Int8MultiArray(Hako_Int8MultiArray &src, HakoCpp_Int8MultiArray &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Int8MultiArray((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_Int8MultiArray_data(HakoCpp_Int8MultiArray &src, Hako_Int8MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_int8));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_int8));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_Int8MultiArray(HakoCpp_Int8MultiArray &src, Hako_Int8MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_MultiArrayLayout(src.layout, dst.layout, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_Int8MultiArray_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Int8MultiArray(HakoCpp_Int8MultiArray &src, Hako_Int8MultiArray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Int8MultiArray out;
    if (!cpp_cpp2pdu_Int8MultiArray(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Int8MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Int8MultiArray));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Int8MultiArray*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Int8MultiArray* hako_create_empty_pdu_Int8MultiArray(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Int8MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Int8MultiArray*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int8MultiArray_HPP_ */
