#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_TransformStamped.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/transform_stamped.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Transform.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_TransformStamped(const char* varray_ptr, Hako_TransformStamped &src, geometry_msgs::msg::TransformStamped &dst)
{
    // Struct convert
    _pdu2ros_Header(varray_ptr, src.header, dst.header);
    // string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    // Struct convert
    _pdu2ros_Transform(varray_ptr, src.transform, dst.transform);
    return 0;
}

static inline int hako_convert_pdu2ros_TransformStamped(Hako_TransformStamped &src, geometry_msgs::msg::TransformStamped &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TransformStamped));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_TransformStamped) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_TransformStamped(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_TransformStamped(geometry_msgs::msg::TransformStamped &src, Hako_TransformStamped &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.child_frame_id, src.child_frame_id.length(),
            dst.child_frame_id, M_ARRAY_SIZE(Hako_TransformStamped, char, child_frame_id));
        // struct convert
        _ros2pdu_Transform(src.transform, dst.transform, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_TransformStamped(geometry_msgs::msg::TransformStamped &src, Hako_TransformStamped** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TransformStamped out;
    if (!_ros2pdu_TransformStamped(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_TransformStamped) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TransformStamped));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TransformStamped));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_TransformStamped) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_TransformStamped*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_ */
