#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ShareObjectOwner.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_ShareObjectOwner.hpp"

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

static inline int cpp_pdu2cpp_ShareObjectOwner(const char* heap_ptr, Hako_ShareObjectOwner &src, HakoCpp_ShareObjectOwner &dst)
{
    // string convertor
    dst.object_name = (const char*)src.object_name;
    // primitive convert
    hako_convert_pdu2cpp(src.owner_id, dst.owner_id);
    // primitive convert
    hako_convert_pdu2cpp(src.last_update, dst.last_update);
    // Struct convert
    cpp_pdu2cpp_Twist(heap_ptr, src.pos, dst.pos);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ShareObjectOwner(Hako_ShareObjectOwner &src, HakoCpp_ShareObjectOwner &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ShareObjectOwner((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ShareObjectOwner(HakoCpp_ShareObjectOwner &src, Hako_ShareObjectOwner &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.object_name, src.object_name.length(),
            dst.object_name, M_ARRAY_SIZE(Hako_ShareObjectOwner, char, object_name));
        dst.object_name[src.object_name.length()] = '\0';
        // primitive convert
        hako_convert_cpp2pdu(src.owner_id, dst.owner_id);
        // primitive convert
        hako_convert_cpp2pdu(src.last_update, dst.last_update);
        // struct convert
        cpp_cpp2pdu_Twist(src.pos, dst.pos, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ShareObjectOwner(HakoCpp_ShareObjectOwner &src, Hako_ShareObjectOwner** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ShareObjectOwner out;
    if (!cpp_cpp2pdu_ShareObjectOwner(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ShareObjectOwner), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ShareObjectOwner));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ShareObjectOwner*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ShareObjectOwner* hako_create_empty_pdu_ShareObjectOwner(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ShareObjectOwner), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ShareObjectOwner*)base_ptr;
}
namespace hako::pdu::msgs::hako_msgs
{
class ShareObjectOwner
{
public:
    ShareObjectOwner() = default;
    ~ShareObjectOwner() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_ShareObjectOwner& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ShareObjectOwner" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_ShareObjectOwner(*(Hako_ShareObjectOwner*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "ShareObjectOwner" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_ShareObjectOwner& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_ShareObjectOwner(cppData, (Hako_ShareObjectOwner**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "ShareObjectOwner" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "ShareObjectOwner" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ShareObjectOwner" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_ */
