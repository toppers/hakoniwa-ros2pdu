#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ImpulseCollision.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_ImpulseCollision.hpp"

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

static inline int cpp_pdu2cpp_ImpulseCollision(const char* heap_ptr, Hako_ImpulseCollision &src, HakoCpp_ImpulseCollision &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.collision, dst.collision);
    // primitive convert
    hako_convert_pdu2cpp(src.is_target_static, dst.is_target_static);
    // primitive convert
    hako_convert_pdu2cpp(src.restitution_coefficient, dst.restitution_coefficient);
    // Struct convert
    cpp_pdu2cpp_Point(heap_ptr, src.self_contact_vector, dst.self_contact_vector);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.normal, dst.normal);
    // Struct convert
    cpp_pdu2cpp_Point(heap_ptr, src.target_contact_vector, dst.target_contact_vector);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.target_velocity, dst.target_velocity);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.target_angular_velocity, dst.target_angular_velocity);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.target_euler, dst.target_euler);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.target_inertia, dst.target_inertia);
    // primitive convert
    hako_convert_pdu2cpp(src.target_mass, dst.target_mass);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ImpulseCollision(Hako_ImpulseCollision &src, HakoCpp_ImpulseCollision &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ImpulseCollision((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ImpulseCollision(HakoCpp_ImpulseCollision &src, Hako_ImpulseCollision &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.collision, dst.collision);
        // primitive convert
        hako_convert_cpp2pdu(src.is_target_static, dst.is_target_static);
        // primitive convert
        hako_convert_cpp2pdu(src.restitution_coefficient, dst.restitution_coefficient);
        // struct convert
        cpp_cpp2pdu_Point(src.self_contact_vector, dst.self_contact_vector, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.normal, dst.normal, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Point(src.target_contact_vector, dst.target_contact_vector, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.target_velocity, dst.target_velocity, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.target_angular_velocity, dst.target_angular_velocity, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.target_euler, dst.target_euler, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.target_inertia, dst.target_inertia, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.target_mass, dst.target_mass);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ImpulseCollision(HakoCpp_ImpulseCollision &src, Hako_ImpulseCollision** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ImpulseCollision out;
    if (!cpp_cpp2pdu_ImpulseCollision(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ImpulseCollision), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ImpulseCollision));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ImpulseCollision*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ImpulseCollision* hako_create_empty_pdu_ImpulseCollision(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ImpulseCollision), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ImpulseCollision*)base_ptr;
}
namespace hako::pdu::msgs::hako_msgs
{
class ImpulseCollision
{
public:
    ImpulseCollision() = default;
    ~ImpulseCollision() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_ImpulseCollision& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ImpulseCollision" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_ImpulseCollision(*(Hako_ImpulseCollision*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "ImpulseCollision" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_ImpulseCollision& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_ImpulseCollision(cppData, (Hako_ImpulseCollision**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "ImpulseCollision" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "ImpulseCollision" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ImpulseCollision" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ImpulseCollision_HPP_ */
