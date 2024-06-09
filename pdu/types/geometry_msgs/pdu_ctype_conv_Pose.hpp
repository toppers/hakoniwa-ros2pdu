#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Pose.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/pose.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Pose(const char* varray_ptr, Hako_Pose &src, geometry_msgs::msg::Pose &dst)
{
    // Struct convert
    _pdu2ros_Point(varray_ptr, src.position, dst.position);
    // Struct convert
    _pdu2ros_Quaternion(varray_ptr, src.orientation, dst.orientation);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Pose(Hako_Pose &src, geometry_msgs::msg::Pose &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Pose));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Pose) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Pose(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Pose(geometry_msgs::msg::Pose &src, Hako_Pose &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Point(src.position, dst.position, dynamic_memory);
        // struct convert
        _ros2pdu_Quaternion(src.orientation, dst.orientation, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Pose(geometry_msgs::msg::Pose &src, Hako_Pose** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Pose out;
    if (!_ros2pdu_Pose(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Pose) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Pose));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Pose));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Pose) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Pose*)base_ptr;
    return total_size;
}
static inline Hako_Pose* hako_create_empty_pdu_Pose(int heap_size)
{
    int total_size = sizeof(Hako_Pose) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Pose));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Pose) + sizeof(HakoPduMetaDataType);
    return (Hako_Pose*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_ */
