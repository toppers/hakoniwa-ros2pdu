#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_RegionOfInterest.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/region_of_interest.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_RegionOfInterest(const char* varray_ptr, Hako_RegionOfInterest &src, sensor_msgs::msg::RegionOfInterest &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.x_offset, dst.x_offset);
    // primitive convert
    hako_convert_pdu2ros(src.y_offset, dst.y_offset);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    // primitive convert
    hako_convert_pdu2ros(src.do_rectify, dst.do_rectify);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_RegionOfInterest(Hako_RegionOfInterest &src, sensor_msgs::msg::RegionOfInterest &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_RegionOfInterest));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_RegionOfInterest) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_RegionOfInterest(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_RegionOfInterest(sensor_msgs::msg::RegionOfInterest &src, Hako_RegionOfInterest &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.x_offset, dst.x_offset);
        // primitive convert
        hako_convert_ros2pdu(src.y_offset, dst.y_offset);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.width, dst.width);
        // primitive convert
        hako_convert_ros2pdu(src.do_rectify, dst.do_rectify);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_RegionOfInterest(sensor_msgs::msg::RegionOfInterest &src, Hako_RegionOfInterest** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_RegionOfInterest out;
    if (!_ros2pdu_RegionOfInterest(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_RegionOfInterest) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_RegionOfInterest));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_RegionOfInterest));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_RegionOfInterest) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_RegionOfInterest*)base_ptr;
    return total_size;
}
static inline Hako_RegionOfInterest* hako_create_empty_pdu_RegionOfInterest(int heap_size)
{
    int total_size = sizeof(Hako_RegionOfInterest) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_RegionOfInterest));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_RegionOfInterest) + sizeof(HakoPduMetaDataType);
    return (Hako_RegionOfInterest*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_ */
