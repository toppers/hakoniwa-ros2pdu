#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_TwistWithCovariance.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/twist_with_covariance.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_TwistWithCovariance_covariance(const char* varray_ptr, Hako_TwistWithCovariance &src, geometry_msgs::msg::TwistWithCovariance &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 36; ++i) {
        hako_convert_pdu2ros(src.covariance[i], dst.covariance[i]);
    }
    return 0;
}

static inline int _pdu2ros_TwistWithCovariance(const char* varray_ptr, Hako_TwistWithCovariance &src, geometry_msgs::msg::TwistWithCovariance &dst)
{
    // Struct convert
    _pdu2ros_Twist(varray_ptr, src.twist, dst.twist);
    // primitive array convertor
    _pdu2ros_primitive_array_TwistWithCovariance_covariance(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_TwistWithCovariance(Hako_TwistWithCovariance &src, geometry_msgs::msg::TwistWithCovariance &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TwistWithCovariance));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_TwistWithCovariance) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_TwistWithCovariance(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_TwistWithCovariance_covariance(geometry_msgs::msg::TwistWithCovariance &src, Hako_TwistWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 36
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.covariance, src.covariance.size(),
        dst.covariance, M_ARRAY_SIZE(Hako_TwistWithCovariance, Hako_float64, covariance));
    return true;
}

static inline bool _ros2pdu_TwistWithCovariance(geometry_msgs::msg::TwistWithCovariance &src, Hako_TwistWithCovariance &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Twist(src.twist, dst.twist, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_TwistWithCovariance_covariance(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_TwistWithCovariance(geometry_msgs::msg::TwistWithCovariance &src, Hako_TwistWithCovariance** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TwistWithCovariance out;
    if (!_ros2pdu_TwistWithCovariance(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_TwistWithCovariance) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TwistWithCovariance));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TwistWithCovariance));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_TwistWithCovariance) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_TwistWithCovariance*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_TwistWithCovariance_HPP_ */
