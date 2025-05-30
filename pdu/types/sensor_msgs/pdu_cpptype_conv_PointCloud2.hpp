#ifndef _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
/*
 * Dependent cpp pdu data
 */
#include "sensor_msgs/pdu_cpptype_PointCloud2.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "sensor_msgs/pdu_cpptype_conv_PointField.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_struct_array_PointCloud2_fields(const char* heap_ptr, Hako_PointCloud2 &src, HakoCpp_PointCloud2 &dst)
{
    // Convert using len and off
    int offset = src._fields_off;
    int length = src._fields_len;
    if (length > 0) {
        dst.fields.resize(length);
        Hako_PointField *temp_struct_ptr = (Hako_PointField *)(heap_ptr + offset);
        for (int i = 0; i < length; ++i) {
            cpp_pdu2cpp_PointField(heap_ptr, *temp_struct_ptr, dst.fields[i]);
            temp_struct_ptr++;
        }
    }
    return 0;
}
static inline int cpp_pdu2cpp_primitive_array_PointCloud2_data(const char* heap_ptr, Hako_PointCloud2 &src, HakoCpp_PointCloud2 &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_uint8));
    }
    return 0;
}

static inline int cpp_pdu2cpp_PointCloud2(const char* heap_ptr, Hako_PointCloud2 &src, HakoCpp_PointCloud2 &dst)
{
    // Struct convert
    cpp_pdu2cpp_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2cpp(src.width, dst.width);
    // struct array convertor
    cpp_pdu2cpp_struct_array_PointCloud2_fields(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.is_bigendian, dst.is_bigendian);
    // primitive convert
    hako_convert_pdu2cpp(src.point_step, dst.point_step);
    // primitive convert
    hako_convert_pdu2cpp(src.row_step, dst.row_step);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_PointCloud2_data(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.is_dense, dst.is_dense);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_PointCloud2(Hako_PointCloud2 &src, HakoCpp_PointCloud2 &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_PointCloud2((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_struct_array_PointCloud2_fields(HakoCpp_PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    dst._fields_len = src.fields.size();
    if (dst._fields_len > 0) {
        Hako_PointField* temp_struct_ptr = (Hako_PointField*)dynamic_memory.allocate(dst._fields_len, sizeof(Hako_PointField));
        dst._fields_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._fields_len; ++i) {
            cpp_cpp2pdu_PointField(src.fields[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._fields_off = dynamic_memory.get_total_size();
    }
    return true;
}
static inline bool cpp_cpp2pdu_primitive_array_PointCloud2_data(HakoCpp_PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_uint8));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_uint8));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_PointCloud2(HakoCpp_PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_cpp2pdu(src.width, dst.width);
        //struct array convert
        cpp_cpp2pdu_struct_array_PointCloud2_fields(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.is_bigendian, dst.is_bigendian);
        // primitive convert
        hako_convert_cpp2pdu(src.point_step, dst.point_step);
        // primitive convert
        hako_convert_cpp2pdu(src.row_step, dst.row_step);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_PointCloud2_data(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.is_dense, dst.is_dense);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_PointCloud2(HakoCpp_PointCloud2 &src, Hako_PointCloud2** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PointCloud2 out;
    if (!cpp_cpp2pdu_PointCloud2(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_PointCloud2), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PointCloud2));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_PointCloud2*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_PointCloud2* hako_create_empty_pdu_PointCloud2(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_PointCloud2), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_PointCloud2*)base_ptr;
}
namespace hako::pdu::msgs::sensor_msgs
{
class PointCloud2
{
public:
    PointCloud2() = default;
    ~PointCloud2() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_PointCloud2& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "PointCloud2" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_PointCloud2(*(Hako_PointCloud2*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "PointCloud2" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_PointCloud2& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_PointCloud2(cppData, (Hako_PointCloud2**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "PointCloud2" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "PointCloud2" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "PointCloud2" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_ */
