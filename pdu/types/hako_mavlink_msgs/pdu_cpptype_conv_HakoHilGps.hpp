#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilGps.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoHilGps.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoHilGps(const char* heap_ptr, Hako_HakoHilGps &src, HakoCpp_HakoHilGps &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_usec, dst.time_usec);
    // primitive convert
    hako_convert_pdu2cpp(src.lat, dst.lat);
    // primitive convert
    hako_convert_pdu2cpp(src.lon, dst.lon);
    // primitive convert
    hako_convert_pdu2cpp(src.alt, dst.alt);
    // primitive convert
    hako_convert_pdu2cpp(src.eph, dst.eph);
    // primitive convert
    hako_convert_pdu2cpp(src.epv, dst.epv);
    // primitive convert
    hako_convert_pdu2cpp(src.vel, dst.vel);
    // primitive convert
    hako_convert_pdu2cpp(src.vn, dst.vn);
    // primitive convert
    hako_convert_pdu2cpp(src.ve, dst.ve);
    // primitive convert
    hako_convert_pdu2cpp(src.vd, dst.vd);
    // primitive convert
    hako_convert_pdu2cpp(src.cog, dst.cog);
    // primitive convert
    hako_convert_pdu2cpp(src.satellites_visible, dst.satellites_visible);
    // primitive convert
    hako_convert_pdu2cpp(src.id, dst.id);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw, dst.yaw);
    // primitive convert
    hako_convert_pdu2cpp(src.fix_type, dst.fix_type);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoHilGps(Hako_HakoHilGps &src, HakoCpp_HakoHilGps &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoHilGps((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoHilGps(HakoCpp_HakoHilGps &src, Hako_HakoHilGps &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_usec, dst.time_usec);
        // primitive convert
        hako_convert_cpp2pdu(src.lat, dst.lat);
        // primitive convert
        hako_convert_cpp2pdu(src.lon, dst.lon);
        // primitive convert
        hako_convert_cpp2pdu(src.alt, dst.alt);
        // primitive convert
        hako_convert_cpp2pdu(src.eph, dst.eph);
        // primitive convert
        hako_convert_cpp2pdu(src.epv, dst.epv);
        // primitive convert
        hako_convert_cpp2pdu(src.vel, dst.vel);
        // primitive convert
        hako_convert_cpp2pdu(src.vn, dst.vn);
        // primitive convert
        hako_convert_cpp2pdu(src.ve, dst.ve);
        // primitive convert
        hako_convert_cpp2pdu(src.vd, dst.vd);
        // primitive convert
        hako_convert_cpp2pdu(src.cog, dst.cog);
        // primitive convert
        hako_convert_cpp2pdu(src.satellites_visible, dst.satellites_visible);
        // primitive convert
        hako_convert_cpp2pdu(src.id, dst.id);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw, dst.yaw);
        // primitive convert
        hako_convert_cpp2pdu(src.fix_type, dst.fix_type);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoHilGps(HakoCpp_HakoHilGps &src, Hako_HakoHilGps** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilGps out;
    if (!cpp_cpp2pdu_HakoHilGps(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilGps), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilGps));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilGps*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilGps* hako_create_empty_pdu_HakoHilGps(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilGps), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilGps*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink_msgs
{
class HakoHilGps
{
public:
    HakoHilGps() = default;
    ~HakoHilGps() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoHilGps& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilGps" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoHilGps(*(Hako_HakoHilGps*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoHilGps" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoHilGps& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoHilGps(cppData, (Hako_HakoHilGps**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoHilGps" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoHilGps" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilGps" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_ */
