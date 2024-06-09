#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/point_cloud2.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_PointField.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_struct_array_PointCloud2_fields(const char* varray_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 4; ++i) {
        _pdu2ros_PointField(varray_ptr, src.fields[i], dst.fields[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_PointCloud2_data(const char* varray_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 176656; ++i) {
        hako_convert_pdu2ros(src.data[i], dst.data[i]);
    }
    return 0;
}

static inline int _pdu2ros_PointCloud2(const char* varray_ptr, Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    // Struct convert
    _pdu2ros_Header(varray_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // struct array convertor
    _pdu2ros_struct_array_PointCloud2_fields(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.is_bigendian, dst.is_bigendian);
    // primitive convert
    hako_convert_pdu2ros(src.point_step, dst.point_step);
    // primitive convert
    hako_convert_pdu2ros(src.row_step, dst.row_step);
    // primitive array convertor
    _pdu2ros_primitive_array_PointCloud2_data(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.is_dense, dst.is_dense);
    return 0;
}

static inline int hako_convert_pdu2ros_PointCloud2(Hako_PointCloud2 &src, sensor_msgs::msg::PointCloud2 &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointCloud2));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_PointCloud2) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_PointCloud2(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_struct_array_PointCloud2_fields(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 4; ++i) {
        _ros2pdu_PointField(src.fields[i], dst.fields[i], dynamic_memory);
    }
    return true;
}
static inline bool _ros2pdu_primitive_array_PointCloud2_data(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 176656
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_PointCloud2, Hako_uint8, data));
    return true;
}

static inline bool _ros2pdu_PointCloud2(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.width, dst.width);
        //struct array convert
        _ros2pdu_struct_array_PointCloud2_fields(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.is_bigendian, dst.is_bigendian);
        // primitive convert
        hako_convert_ros2pdu(src.point_step, dst.point_step);
        // primitive convert
        hako_convert_ros2pdu(src.row_step, dst.row_step);
        //primitive array copy
        _ros2pdu_primitive_array_PointCloud2_data(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.is_dense, dst.is_dense);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_PointCloud2(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PointCloud2 out;
    if (!_ros2pdu_PointCloud2(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_PointCloud2) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PointCloud2));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointCloud2));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PointCloud2) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_PointCloud2*)base_ptr;
    return total_size;
}
static inline Hako_PointCloud2* hako_create_empty_pdu_PointCloud2(int heap_size)
{
    int total_size = sizeof(Hako_PointCloud2) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointCloud2));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PointCloud2) + sizeof(HakoPduMetaDataType);
    return (Hako_PointCloud2*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_ */
