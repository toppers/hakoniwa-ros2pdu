#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Collision_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Collision_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_Collision.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_Collision.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Point.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_struct_array_Collision_contact_position(const char* heap_ptr, Hako_Collision &src, HakoCpp_Collision &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 10; ++i) {
        cpp_pdu2cpp_Point(heap_ptr, src.contact_position[i], dst.contact_position[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_Collision(const char* heap_ptr, Hako_Collision &src, HakoCpp_Collision &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.collision, dst.collision);
    // primitive convert
    hako_convert_pdu2cpp(src.contact_num, dst.contact_num);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.relative_velocity, dst.relative_velocity);
    // struct array convertor
    cpp_pdu2cpp_struct_array_Collision_contact_position(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.restitution_coefficient, dst.restitution_coefficient);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Collision(Hako_Collision &src, HakoCpp_Collision &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Collision((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_struct_array_Collision_contact_position(HakoCpp_Collision &src, Hako_Collision &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 10; ++i) {
        cpp_cpp2pdu_Point(src.contact_position[i], dst.contact_position[i], dynamic_memory);
    }
    return true;
}

static inline bool cpp_cpp2pdu_Collision(HakoCpp_Collision &src, Hako_Collision &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.collision, dst.collision);
        // primitive convert
        hako_convert_cpp2pdu(src.contact_num, dst.contact_num);
        // struct convert
        cpp_cpp2pdu_Vector3(src.relative_velocity, dst.relative_velocity, dynamic_memory);
        //struct array convert
        cpp_cpp2pdu_struct_array_Collision_contact_position(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.restitution_coefficient, dst.restitution_coefficient);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Collision(HakoCpp_Collision &src, Hako_Collision** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Collision out;
    if (!cpp_cpp2pdu_Collision(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Collision), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Collision));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Collision*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Collision* hako_create_empty_pdu_Collision(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Collision), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Collision*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Collision_HPP_ */
