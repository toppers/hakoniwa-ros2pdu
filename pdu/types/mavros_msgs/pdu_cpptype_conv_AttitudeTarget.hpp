#ifndef _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "mavros_msgs/pdu_ctype_AttitudeTarget.h"
/*
 * Dependent cpp pdu data
 */
#include "mavros_msgs/pdu_cpptype_AttitudeTarget.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_AttitudeTarget(const char* heap_ptr, Hako_AttitudeTarget &src, HakoCpp_AttitudeTarget &dst)
{
    // Struct convert
    cpp_pdu2cpp_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.type_mask, dst.type_mask);
    // Struct convert
    cpp_pdu2cpp_Quaternion(heap_ptr, src.orientation, dst.orientation);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.body_rate, dst.body_rate);
    // primitive convert
    hako_convert_pdu2cpp(src.thrust, dst.thrust);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_AttitudeTarget(Hako_AttitudeTarget &src, HakoCpp_AttitudeTarget &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_AttitudeTarget((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_AttitudeTarget(HakoCpp_AttitudeTarget &src, Hako_AttitudeTarget &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.type_mask, dst.type_mask);
        // struct convert
        cpp_cpp2pdu_Quaternion(src.orientation, dst.orientation, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.body_rate, dst.body_rate, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.thrust, dst.thrust);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_AttitudeTarget(HakoCpp_AttitudeTarget &src, Hako_AttitudeTarget** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_AttitudeTarget out;
    if (!cpp_cpp2pdu_AttitudeTarget(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_AttitudeTarget), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_AttitudeTarget));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_AttitudeTarget*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_AttitudeTarget* hako_create_empty_pdu_AttitudeTarget(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_AttitudeTarget), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_AttitudeTarget*)base_ptr;
}
namespace hako::pdu::msgs::mavros_msgs
{
class AttitudeTarget
{
public:
    AttitudeTarget() = default;
    ~AttitudeTarget() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_AttitudeTarget& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "AttitudeTarget" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_AttitudeTarget(*(Hako_AttitudeTarget*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "AttitudeTarget" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_AttitudeTarget& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_AttitudeTarget(cppData, (Hako_AttitudeTarget**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "AttitudeTarget" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "AttitudeTarget" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "AttitudeTarget" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_AttitudeTarget_HPP_ */
