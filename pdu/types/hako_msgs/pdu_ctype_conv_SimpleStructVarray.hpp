#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleStructVarray_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleStructVarray_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_SimpleStructVarray.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/simple_struct_varray.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_SimpleVarray.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_string_array_SimpleStructVarray_fixed_str(const char* varray_ptr, Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    (void)hako_convert_pdu2ros_array_string<M_ARRAY_SIZE(Hako_SimpleStructVarray, Hako_cstring, fixed_str), 2>(
        src.fixed_str, dst.fixed_str);
    return 0;
}
static inline int _pdu2ros_string_array_SimpleStructVarray_varray_str(const char* varray_ptr, Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    // Convert using len and off
    int offset = src._varray_str_off;
    int length = src._varray_str_len;
    if (length > 0) {
        Hako_cstring *temp_struct_ptr = (Hako_cstring *)(varray_ptr + offset);
        hako_convert_pdu2ros_array_string_varray(temp_struct_ptr, dst.varray_str, length);
    }
    return 0;
}
static inline int _pdu2ros_struct_array_SimpleStructVarray_fixed_array(const char* varray_ptr, Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 5; ++i) {
        _pdu2ros_SimpleVarray(varray_ptr, src.fixed_array[i], dst.fixed_array[i]);
    }
    return 0;
}
static inline int _pdu2ros_struct_array_SimpleStructVarray_data(const char* varray_ptr, Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        Hako_SimpleVarray *temp_struct_ptr = (Hako_SimpleVarray *)(varray_ptr + offset);
        for (int i = 0; i < length; ++i) {
            _pdu2ros_SimpleVarray(varray_ptr, *temp_struct_ptr, dst.data[i]);
            temp_struct_ptr++;
        }
    }
    return 0;
}

static inline int _pdu2ros_SimpleStructVarray(const char* varray_ptr, Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.aaa, dst.aaa);
    // string array convertor
    _pdu2ros_string_array_SimpleStructVarray_fixed_str(varray_ptr, src, dst);
    // string array convertor
    _pdu2ros_string_array_SimpleStructVarray_varray_str(varray_ptr, src, dst);
    // struct array convertor
    _pdu2ros_struct_array_SimpleStructVarray_fixed_array(varray_ptr, src, dst);
    // struct array convertor
    _pdu2ros_struct_array_SimpleStructVarray_data(varray_ptr, src, dst);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_SimpleStructVarray(Hako_SimpleStructVarray &src, hako_msgs::msg::SimpleStructVarray &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_SimpleStructVarray));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_SimpleStructVarray) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_SimpleStructVarray(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_string_array_SimpleStructVarray_fixed_str(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed string 2
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array_string<2, M_ARRAY_SIZE(Hako_SimpleStructVarray, Hako_cstring, fixed_str)>(
        src.fixed_str, dst.fixed_str);
    return true;
}
static inline bool _ros2pdu_string_array_SimpleStructVarray_varray_str(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray string
    dst._varray_str_len = src.varray_str.size();
    if (dst._varray_str_len > 0) {
        Hako_cstring* temp_ptr = (Hako_cstring*)dynamic_memory.allocate(dst._varray_str_len, sizeof(Hako_cstring));
        (void)hako_convert_ros2pdu_array_string_varray(src.varray_str, temp_ptr);
        dst._varray_str_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._varray_str_off = dynamic_memory.get_total_size();
    }
    return true;
}
static inline bool _ros2pdu_struct_array_SimpleStructVarray_fixed_array(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 5; ++i) {
        _ros2pdu_SimpleVarray(src.fixed_array[i], dst.fixed_array[i], dynamic_memory);
    }
    return true;
}
static inline bool _ros2pdu_struct_array_SimpleStructVarray_data(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        Hako_SimpleVarray* temp_struct_ptr = (Hako_SimpleVarray*)dynamic_memory.allocate(dst._data_len, sizeof(Hako_SimpleVarray));
        dst._data_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._data_len; ++i) {
            _ros2pdu_SimpleVarray(src.data[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool _ros2pdu_SimpleStructVarray(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.aaa, dst.aaa);
        // string array convert
        _ros2pdu_string_array_SimpleStructVarray_fixed_str(src, dst, dynamic_memory);
        // string array convert
        _ros2pdu_string_array_SimpleStructVarray_varray_str(src, dst, dynamic_memory);
        //struct array convert
        _ros2pdu_struct_array_SimpleStructVarray_fixed_array(src, dst, dynamic_memory);
        //struct array convert
        _ros2pdu_struct_array_SimpleStructVarray_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_SimpleStructVarray(hako_msgs::msg::SimpleStructVarray &src, Hako_SimpleStructVarray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_SimpleStructVarray out;
    if (!_ros2pdu_SimpleStructVarray(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_SimpleStructVarray) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_SimpleStructVarray));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_SimpleStructVarray));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_SimpleStructVarray) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_SimpleStructVarray*)base_ptr;
    return total_size;
}
static inline Hako_SimpleStructVarray* hako_create_empty_pdu_SimpleStructVarray(int heap_size)
{
    int total_size = sizeof(Hako_SimpleStructVarray) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_SimpleStructVarray));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_SimpleStructVarray) + sizeof(HakoPduMetaDataType);
    return (Hako_SimpleStructVarray*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleStructVarray_HPP_ */
