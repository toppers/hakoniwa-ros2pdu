#ifndef _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_TwistWithCovariance.h"
/*
 * Dependent cpp pdu data
 */
#include "geometry_msgs/pdu_cpptype_TwistWithCovariance.hpp"

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
static inline int cpp_pdu2cpp_primitive_array_TwistWithCovariance_covariance(const char* heap_ptr, Hako_TwistWithCovariance &src, HakoCpp_TwistWithCovariance &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 36; ++i) {
        hako_convert_pdu2cpp(src.covariance[i], dst.covariance[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_TwistWithCovariance(const char* heap_ptr, Hako_TwistWithCovariance &src, HakoCpp_TwistWithCovariance &dst)
{
    // Struct convert
    cpp_pdu2cpp_Twist(heap_ptr, src.twist, dst.twist);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_TwistWithCovariance_covariance(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_TwistWithCovariance(Hako_TwistWithCovariance &src, HakoCpp_TwistWithCovariance &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_TwistWithCovariance((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_TwistWithCovariance_covariance(HakoCpp_TwistWithCovariance &src, Hako_TwistWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 36
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.covariance, src.covariance.size(),
        dst.covariance, M_ARRAY_SIZE(Hako_TwistWithCovariance, Hako_float64, covariance));
    return true;
}

static inline bool cpp_cpp2pdu_TwistWithCovariance(HakoCpp_TwistWithCovariance &src, Hako_TwistWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Twist(src.twist, dst.twist, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_TwistWithCovariance_covariance(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_TwistWithCovariance(HakoCpp_TwistWithCovariance &src, Hako_TwistWithCovariance** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TwistWithCovariance out;
    if (!cpp_cpp2pdu_TwistWithCovariance(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_TwistWithCovariance), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TwistWithCovariance));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_TwistWithCovariance*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_TwistWithCovariance* hako_create_empty_pdu_TwistWithCovariance(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_TwistWithCovariance), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_TwistWithCovariance*)base_ptr;
}
namespace hako::pdu::msgs::geometry_msgs
{
class TwistWithCovariance
{
public:
    TwistWithCovariance() = default;
    ~TwistWithCovariance() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_TwistWithCovariance& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "TwistWithCovariance" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_TwistWithCovariance(*(Hako_TwistWithCovariance*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "TwistWithCovariance" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_TwistWithCovariance& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_TwistWithCovariance(cppData, (Hako_TwistWithCovariance**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "TwistWithCovariance" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "TwistWithCovariance" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "TwistWithCovariance" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_ */
