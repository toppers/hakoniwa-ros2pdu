#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoATTITUDE_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoATTITUDE_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoATTITUDE.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoATTITUDE.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoATTITUDE(const char* heap_ptr, Hako_HakoATTITUDE &src, HakoCpp_HakoATTITUDE &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_boot_ms, dst.time_boot_ms);
    // primitive convert
    hako_convert_pdu2cpp(src.roll, dst.roll);
    // primitive convert
    hako_convert_pdu2cpp(src.pitch, dst.pitch);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw, dst.yaw);
    // primitive convert
    hako_convert_pdu2cpp(src.rollspeed, dst.rollspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.pitchspeed, dst.pitchspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.yawspeed, dst.yawspeed);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoATTITUDE(Hako_HakoATTITUDE &src, HakoCpp_HakoATTITUDE &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoATTITUDE((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoATTITUDE(HakoCpp_HakoATTITUDE &src, Hako_HakoATTITUDE &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_boot_ms, dst.time_boot_ms);
        // primitive convert
        hako_convert_cpp2pdu(src.roll, dst.roll);
        // primitive convert
        hako_convert_cpp2pdu(src.pitch, dst.pitch);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw, dst.yaw);
        // primitive convert
        hako_convert_cpp2pdu(src.rollspeed, dst.rollspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.pitchspeed, dst.pitchspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.yawspeed, dst.yawspeed);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoATTITUDE(HakoCpp_HakoATTITUDE &src, Hako_HakoATTITUDE** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoATTITUDE out;
    if (!cpp_cpp2pdu_HakoATTITUDE(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoATTITUDE), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoATTITUDE));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoATTITUDE*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoATTITUDE* hako_create_empty_pdu_HakoATTITUDE(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoATTITUDE), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoATTITUDE*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink_msgs
{
class HakoATTITUDE
{
public:
    HakoATTITUDE() = default;
    ~HakoATTITUDE() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoATTITUDE& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoATTITUDE" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoATTITUDE(*(Hako_HakoATTITUDE*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoATTITUDE" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoATTITUDE& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoATTITUDE(cppData, (Hako_HakoATTITUDE**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoATTITUDE" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoATTITUDE" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoATTITUDE" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoATTITUDE_HPP_ */
