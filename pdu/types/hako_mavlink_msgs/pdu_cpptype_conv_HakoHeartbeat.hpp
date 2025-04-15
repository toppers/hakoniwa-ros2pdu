#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHeartbeat.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoHeartbeat.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoHeartbeat(const char* heap_ptr, Hako_HakoHeartbeat &src, HakoCpp_HakoHeartbeat &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.type, dst.type);
    // primitive convert
    hako_convert_pdu2cpp(src.autopilot, dst.autopilot);
    // primitive convert
    hako_convert_pdu2cpp(src.base_mode, dst.base_mode);
    // primitive convert
    hako_convert_pdu2cpp(src.custom_mode, dst.custom_mode);
    // primitive convert
    hako_convert_pdu2cpp(src.system_status, dst.system_status);
    // primitive convert
    hako_convert_pdu2cpp(src.mavlink_version, dst.mavlink_version);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoHeartbeat(Hako_HakoHeartbeat &src, HakoCpp_HakoHeartbeat &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoHeartbeat((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoHeartbeat(HakoCpp_HakoHeartbeat &src, Hako_HakoHeartbeat &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.type, dst.type);
        // primitive convert
        hako_convert_cpp2pdu(src.autopilot, dst.autopilot);
        // primitive convert
        hako_convert_cpp2pdu(src.base_mode, dst.base_mode);
        // primitive convert
        hako_convert_cpp2pdu(src.custom_mode, dst.custom_mode);
        // primitive convert
        hako_convert_cpp2pdu(src.system_status, dst.system_status);
        // primitive convert
        hako_convert_cpp2pdu(src.mavlink_version, dst.mavlink_version);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoHeartbeat(HakoCpp_HakoHeartbeat &src, Hako_HakoHeartbeat** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHeartbeat out;
    if (!cpp_cpp2pdu_HakoHeartbeat(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHeartbeat), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHeartbeat));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHeartbeat*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHeartbeat* hako_create_empty_pdu_HakoHeartbeat(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHeartbeat), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHeartbeat*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink_msgs
{
class HakoHeartbeat
{
public:
    HakoHeartbeat() = default;
    ~HakoHeartbeat() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoHeartbeat& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHeartbeat" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoHeartbeat(*(Hako_HakoHeartbeat*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoHeartbeat" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoHeartbeat& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoHeartbeat(cppData, (Hako_HakoHeartbeat**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoHeartbeat" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoHeartbeat" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHeartbeat" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_ */
