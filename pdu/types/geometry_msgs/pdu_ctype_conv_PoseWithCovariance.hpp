#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_PoseWithCovariance_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_PoseWithCovariance_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_PoseWithCovariance.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/pose_with_covariance.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_PoseWithCovariance_covariance(const char* varray_ptr, Hako_PoseWithCovariance &src, geometry_msgs::msg::PoseWithCovariance &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 36; ++i) {
        hako_convert_pdu2ros(src.covariance[i], dst.covariance[i]);
    }
    return 0;
}

static inline int _pdu2ros_PoseWithCovariance(const char* varray_ptr, Hako_PoseWithCovariance &src, geometry_msgs::msg::PoseWithCovariance &dst)
{
    // Struct convert
    _pdu2ros_Pose(varray_ptr, src.pose, dst.pose);
    // primitive array convertor
    _pdu2ros_primitive_array_PoseWithCovariance_covariance(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_PoseWithCovariance(Hako_PoseWithCovariance &src, geometry_msgs::msg::PoseWithCovariance &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PoseWithCovariance));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_PoseWithCovariance) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_PoseWithCovariance(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_PoseWithCovariance_covariance(geometry_msgs::msg::PoseWithCovariance &src, Hako_PoseWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 36
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.covariance, src.covariance.size(),
        dst.covariance, M_ARRAY_SIZE(Hako_PoseWithCovariance, Hako_float64, covariance));
    return true;
}

static inline bool _ros2pdu_PoseWithCovariance(geometry_msgs::msg::PoseWithCovariance &src, Hako_PoseWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Pose(src.pose, dst.pose, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_PoseWithCovariance_covariance(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_PoseWithCovariance(geometry_msgs::msg::PoseWithCovariance &src, Hako_PoseWithCovariance** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PoseWithCovariance out;
    if (!_ros2pdu_PoseWithCovariance(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_PoseWithCovariance) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PoseWithCovariance));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PoseWithCovariance));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PoseWithCovariance) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_PoseWithCovariance*)base_ptr;
    return total_size;
}
static inline Hako_PoseWithCovariance* hako_create_empty_pdu_PoseWithCovariance(int heap_size)
{
    int total_size = sizeof(Hako_PoseWithCovariance) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PoseWithCovariance));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PoseWithCovariance) + sizeof(HakoPduMetaDataType);
    return (Hako_PoseWithCovariance*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_PoseWithCovariance_HPP_ */
