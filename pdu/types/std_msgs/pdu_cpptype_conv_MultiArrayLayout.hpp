#ifndef _PDU_CPPTYPE_CONV_HAKO_std_msgs_MultiArrayLayout_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_std_msgs_MultiArrayLayout_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_MultiArrayLayout.h"
/*
 * Dependent cpp pdu data
 */
#include "std_msgs/pdu_cpptype_MultiArrayLayout.hpp"

/*
 * Dependent Convertors
 */
#include "std_msgs/pdu_cpptype_conv_MultiArrayDimension.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_struct_array_MultiArrayLayout_dim(const char* heap_ptr, Hako_MultiArrayLayout &src, HakoCpp_MultiArrayLayout &dst)
{
    // Convert using len and off
    int offset = src._dim_off;
    int length = src._dim_len;
    if (length > 0) {
        dst.dim.resize(length);
        Hako_MultiArrayDimension *temp_struct_ptr = (Hako_MultiArrayDimension *)(heap_ptr + offset);
        for (int i = 0; i < length; ++i) {
            cpp_pdu2cpp_MultiArrayDimension(heap_ptr, *temp_struct_ptr, dst.dim[i]);
            temp_struct_ptr++;
        }
    }
    return 0;
}

static inline int cpp_pdu2cpp_MultiArrayLayout(const char* heap_ptr, Hako_MultiArrayLayout &src, HakoCpp_MultiArrayLayout &dst)
{
    // struct array convertor
    cpp_pdu2cpp_struct_array_MultiArrayLayout_dim(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.data_offset, dst.data_offset);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_MultiArrayLayout(Hako_MultiArrayLayout &src, HakoCpp_MultiArrayLayout &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_MultiArrayLayout((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_struct_array_MultiArrayLayout_dim(HakoCpp_MultiArrayLayout &src, Hako_MultiArrayLayout &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    dst._dim_len = src.dim.size();
    if (dst._dim_len > 0) {
        Hako_MultiArrayDimension* temp_struct_ptr = (Hako_MultiArrayDimension*)dynamic_memory.allocate(dst._dim_len, sizeof(Hako_MultiArrayDimension));
        dst._dim_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._dim_len; ++i) {
            cpp_cpp2pdu_MultiArrayDimension(src.dim[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._dim_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_MultiArrayLayout(HakoCpp_MultiArrayLayout &src, Hako_MultiArrayLayout &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //struct array convert
        cpp_cpp2pdu_struct_array_MultiArrayLayout_dim(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.data_offset, dst.data_offset);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_MultiArrayLayout(HakoCpp_MultiArrayLayout &src, Hako_MultiArrayLayout** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MultiArrayLayout out;
    if (!cpp_cpp2pdu_MultiArrayLayout(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MultiArrayLayout), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MultiArrayLayout));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MultiArrayLayout*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MultiArrayLayout* hako_create_empty_pdu_MultiArrayLayout(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MultiArrayLayout), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MultiArrayLayout*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_std_msgs_MultiArrayLayout_HPP_ */
