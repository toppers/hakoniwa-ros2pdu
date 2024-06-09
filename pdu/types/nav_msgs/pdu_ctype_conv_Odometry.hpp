#ifndef _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_
#define _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "nav_msgs/pdu_ctype_Odometry.h"
/*
 * Dependent ros data
 */
#include "nav_msgs/msg/odometry.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_PoseWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_TwistWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Odometry(const char* varray_ptr, Hako_Odometry &src, nav_msgs::msg::Odometry &dst)
{
    // Struct convert
    _pdu2ros_Header(varray_ptr, src.header, dst.header);
    // string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    // Struct convert
    _pdu2ros_PoseWithCovariance(varray_ptr, src.pose, dst.pose);
    // Struct convert
    _pdu2ros_TwistWithCovariance(varray_ptr, src.twist, dst.twist);
    return 0;
}

static inline int hako_convert_pdu2ros_Odometry(Hako_Odometry &src, nav_msgs::msg::Odometry &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Odometry));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Odometry) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Odometry(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Odometry(nav_msgs::msg::Odometry &src, Hako_Odometry &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.child_frame_id, src.child_frame_id.length(),
            dst.child_frame_id, M_ARRAY_SIZE(Hako_Odometry, char, child_frame_id));
        // struct convert
        _ros2pdu_PoseWithCovariance(src.pose, dst.pose, dynamic_memory);
        // struct convert
        _ros2pdu_TwistWithCovariance(src.twist, dst.twist, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Odometry(nav_msgs::msg::Odometry &src, Hako_Odometry** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Odometry out;
    if (!_ros2pdu_Odometry(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Odometry) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Odometry));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Odometry));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Odometry) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Odometry*)base_ptr;
    return total_size;
}
static inline Hako_Odometry* hako_create_empty_pdu_Odometry(int heap_size)
{
    int total_size = sizeof(Hako_Odometry) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Odometry));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Odometry) + sizeof(HakoPduMetaDataType);
    return (Hako_Odometry*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_ */
