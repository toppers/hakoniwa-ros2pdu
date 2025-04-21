#ifndef _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointField.h"
/*
 * Dependent cpp pdu data
 */
#include "sensor_msgs/pdu_cpptype_PointField.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_PointField(const char* heap_ptr, Hako_PointField &src, HakoCpp_PointField &dst)
{
    // string convertor
    dst.name = (const char*)src.name;
    // primitive convert
    hako_convert_pdu2cpp(src.offset, dst.offset);
    // primitive convert
    hako_convert_pdu2cpp(src.datatype, dst.datatype);
    // primitive convert
    hako_convert_pdu2cpp(src.count, dst.count);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_PointField(Hako_PointField &src, HakoCpp_PointField &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_PointField((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_PointField(HakoCpp_PointField &src, Hako_PointField &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.name, src.name.length(),
            dst.name, M_ARRAY_SIZE(Hako_PointField, char, name));
        dst.name[src.name.length()] = '\0';
        // primitive convert
        hako_convert_cpp2pdu(src.offset, dst.offset);
        // primitive convert
        hako_convert_cpp2pdu(src.datatype, dst.datatype);
        // primitive convert
        hako_convert_cpp2pdu(src.count, dst.count);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_PointField(HakoCpp_PointField &src, Hako_PointField** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PointField out;
    if (!cpp_cpp2pdu_PointField(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_PointField), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PointField));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_PointField*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_PointField* hako_create_empty_pdu_PointField(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_PointField), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_PointField*)base_ptr;
}
namespace hako::pdu::msgs::sensor_msgs
{
class PointField
{
public:
    PointField() = default;
    ~PointField() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_PointField& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "PointField" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_PointField(*(Hako_PointField*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "PointField" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_PointField& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_PointField(cppData, (Hako_PointField**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "PointField" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "PointField" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "PointField" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_ */
