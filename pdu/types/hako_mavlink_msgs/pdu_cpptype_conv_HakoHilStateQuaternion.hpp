#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilStateQuaternion.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoHilStateQuaternion.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_HakoHilStateQuaternion_attitude_quaternion(const char* heap_ptr, Hako_HakoHilStateQuaternion &src, HakoCpp_HakoHilStateQuaternion &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 4; ++i) {
        hako_convert_pdu2cpp(src.attitude_quaternion[i], dst.attitude_quaternion[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_HakoHilStateQuaternion(const char* heap_ptr, Hako_HakoHilStateQuaternion &src, HakoCpp_HakoHilStateQuaternion &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_usec, dst.time_usec);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_HakoHilStateQuaternion_attitude_quaternion(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.rollspeed, dst.rollspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.pitchspeed, dst.pitchspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.yawspeed, dst.yawspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.lat, dst.lat);
    // primitive convert
    hako_convert_pdu2cpp(src.lon, dst.lon);
    // primitive convert
    hako_convert_pdu2cpp(src.alt, dst.alt);
    // primitive convert
    hako_convert_pdu2cpp(src.vx, dst.vx);
    // primitive convert
    hako_convert_pdu2cpp(src.vy, dst.vy);
    // primitive convert
    hako_convert_pdu2cpp(src.vz, dst.vz);
    // primitive convert
    hako_convert_pdu2cpp(src.ind_airspeed, dst.ind_airspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.true_airspeed, dst.true_airspeed);
    // primitive convert
    hako_convert_pdu2cpp(src.xacc, dst.xacc);
    // primitive convert
    hako_convert_pdu2cpp(src.yacc, dst.yacc);
    // primitive convert
    hako_convert_pdu2cpp(src.zacc, dst.zacc);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion &src, HakoCpp_HakoHilStateQuaternion &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoHilStateQuaternion((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_HakoHilStateQuaternion_attitude_quaternion(HakoCpp_HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 4
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.attitude_quaternion, src.attitude_quaternion.size(),
        dst.attitude_quaternion, M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion));
    return true;
}

static inline bool cpp_cpp2pdu_HakoHilStateQuaternion(HakoCpp_HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_usec, dst.time_usec);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_HakoHilStateQuaternion_attitude_quaternion(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.rollspeed, dst.rollspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.pitchspeed, dst.pitchspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.yawspeed, dst.yawspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.lat, dst.lat);
        // primitive convert
        hako_convert_cpp2pdu(src.lon, dst.lon);
        // primitive convert
        hako_convert_cpp2pdu(src.alt, dst.alt);
        // primitive convert
        hako_convert_cpp2pdu(src.vx, dst.vx);
        // primitive convert
        hako_convert_cpp2pdu(src.vy, dst.vy);
        // primitive convert
        hako_convert_cpp2pdu(src.vz, dst.vz);
        // primitive convert
        hako_convert_cpp2pdu(src.ind_airspeed, dst.ind_airspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.true_airspeed, dst.true_airspeed);
        // primitive convert
        hako_convert_cpp2pdu(src.xacc, dst.xacc);
        // primitive convert
        hako_convert_cpp2pdu(src.yacc, dst.yacc);
        // primitive convert
        hako_convert_cpp2pdu(src.zacc, dst.zacc);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoHilStateQuaternion(HakoCpp_HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilStateQuaternion out;
    if (!cpp_cpp2pdu_HakoHilStateQuaternion(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilStateQuaternion), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilStateQuaternion));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilStateQuaternion*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilStateQuaternion* hako_create_empty_pdu_HakoHilStateQuaternion(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilStateQuaternion), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilStateQuaternion*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink_msgs
{
class HakoHilStateQuaternion
{
public:
    HakoHilStateQuaternion() = default;
    ~HakoHilStateQuaternion() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoHilStateQuaternion& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilStateQuaternion" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoHilStateQuaternion(*(Hako_HakoHilStateQuaternion*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoHilStateQuaternion" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoHilStateQuaternion& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoHilStateQuaternion(cppData, (Hako_HakoHilStateQuaternion**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoHilStateQuaternion" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoHilStateQuaternion" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilStateQuaternion" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_ */
