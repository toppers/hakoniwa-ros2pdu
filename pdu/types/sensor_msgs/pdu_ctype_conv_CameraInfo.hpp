#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_CameraInfo.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/camera_info.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_RegionOfInterest.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_CameraInfo_d(const char* varray_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 5; ++i) {
        hako_convert_pdu2ros(src.d[i], dst.d[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_k(const char* varray_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.k[i], dst.k[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_r(const char* varray_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 9; ++i) {
        hako_convert_pdu2ros(src.r[i], dst.r[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_CameraInfo_p(const char* varray_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 12; ++i) {
        hako_convert_pdu2ros(src.p[i], dst.p[i]);
    }
    return 0;
}

static inline int _pdu2ros_CameraInfo(const char* varray_ptr, Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    // Struct convert
    _pdu2ros_Header(base_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // string convertor
    dst.distortion_model = (const char*)src.distortion_model;
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_d(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_k(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_r(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_CameraInfo_p(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.binning_x, dst.binning_x);
    // primitive convert
    hako_convert_pdu2ros(src.binning_y, dst.binning_y);
    // Struct convert
    _pdu2ros_RegionOfInterest(base_ptr, src.roi, dst.roi);
    return 0;
}

static inline int hako_convert_pdu2ros_CameraInfo(Hako_CameraInfo &src, sensor_msgs::msg::CameraInfo &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_CameraInfo));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_CameraInfo) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_CameraInfo(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_CameraInfo_d(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 5
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.d, src.d.size(),
        dst.d, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, d));
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_k(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.k, src.k.size(),
        dst.k, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, k));
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_r(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 9
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.r, src.r.size(),
        dst.r, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, r));
    return true;
}
static inline bool _ros2pdu_primitive_array_CameraInfo_p(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 12
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.p, src.p.size(),
        dst.p, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, p));
    return true;
}

static inline bool _ros2pdu_CameraInfo(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.width, dst.width);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.distortion_model, src.distortion_model.length(),
            dst.distortion_model, M_ARRAY_SIZE(Hako_CameraInfo, char, distortion_model));
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_d(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_k(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_r(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_CameraInfo_p(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.binning_x, dst.binning_x);
        // primitive convert
        hako_convert_ros2pdu(src.binning_y, dst.binning_y);
        // struct convert
        _ros2pdu_RegionOfInterest(src.roi, dst.roi, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_CameraInfo(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_CameraInfo out;
    if (!_ros2pdu_CameraInfo(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_CameraInfo) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_CameraInfo));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_CameraInfo));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_CameraInfo) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_CameraInfo*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_ */
