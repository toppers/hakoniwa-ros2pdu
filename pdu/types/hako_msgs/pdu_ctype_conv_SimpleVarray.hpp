#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleVarray_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleVarray_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_SimpleVarray.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/simple_varray.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_SimpleVarray_data(const char* varray_ptr, Hako_SimpleVarray &src, hako_msgs::msg::SimpleVarray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), varray_ptr + offset, length * sizeof(Hako_int8));
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_SimpleVarray_fixed_array(const char* varray_ptr, Hako_SimpleVarray &src, hako_msgs::msg::SimpleVarray &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 10; ++i) {
        hako_convert_pdu2ros(src.fixed_array[i], dst.fixed_array[i]);
    }
    return 0;
}

static inline int _pdu2ros_SimpleVarray(const char* varray_ptr, Hako_SimpleVarray &src, hako_msgs::msg::SimpleVarray &dst)
{
    // primitive array convertor
    _pdu2ros_primitive_array_SimpleVarray_data(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_SimpleVarray_fixed_array(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.p_mem1, dst.p_mem1);
    return 0;
}

static inline int hako_convert_pdu2ros_SimpleVarray(Hako_SimpleVarray &src, hako_msgs::msg::SimpleVarray &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_SimpleVarray));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_SimpleVarray) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_SimpleVarray(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_SimpleVarray_data(hako_msgs::msg::SimpleVarray &src, Hako_SimpleVarray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_int8));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_int8));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}
static inline bool _ros2pdu_primitive_array_SimpleVarray_fixed_array(hako_msgs::msg::SimpleVarray &src, Hako_SimpleVarray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 10
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.fixed_array, src.fixed_array.size(),
        dst.fixed_array, M_ARRAY_SIZE(Hako_SimpleVarray, Hako_int8, fixed_array));
    return true;
}

static inline bool _ros2pdu_SimpleVarray(hako_msgs::msg::SimpleVarray &src, Hako_SimpleVarray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //primitive array copy
        _ros2pdu_primitive_array_SimpleVarray_data(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_SimpleVarray_fixed_array(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.p_mem1, dst.p_mem1);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_SimpleVarray(hako_msgs::msg::SimpleVarray &src, Hako_SimpleVarray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_SimpleVarray out;
    if (!_ros2pdu_SimpleVarray(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_SimpleVarray) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_SimpleVarray));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_SimpleVarray));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_SimpleVarray) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_SimpleVarray*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_SimpleVarray_HPP_ */
