#ifndef _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_
#define _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "tf2_msgs/pdu_ctype_TFMessage.h"
/*
 * Dependent ros data
 */
#include "tf2_msgs/msg/tf_message.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Transform.hpp"
#include "geometry_msgs/pdu_ctype_conv_TransformStamped.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_struct_array_TFMessage_transforms(const char* varray_ptr, Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 1; ++i) {
        _pdu2ros_TransformStamped(varray_ptr, src.transforms[i], dst.transforms[i]);
    }
    return 0;
}

static inline int _pdu2ros_TFMessage(const char* varray_ptr, Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    // struct array convertor
    _pdu2ros_struct_array_TFMessage_transforms(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_TFMessage(Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TFMessage));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_TFMessage) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_TFMessage(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_struct_array_TFMessage_transforms(tf2_msgs::msg::TFMessage &src, Hako_TFMessage &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 1; ++i) {
        _ros2pdu_TransformStamped(src.transforms[i], dst.transforms[i], dynamic_memory);
    }
    return true;
}

static inline bool _ros2pdu_TFMessage(tf2_msgs::msg::TFMessage &src, Hako_TFMessage &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //struct array convert
        _ros2pdu_struct_array_TFMessage_transforms(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_TFMessage(tf2_msgs::msg::TFMessage &src, Hako_TFMessage** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TFMessage out;
    if (!_ros2pdu_TFMessage(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_TFMessage) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TFMessage));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TFMessage));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_TFMessage) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_TFMessage*)base_ptr;
    return total_size;
}
static inline Hako_TFMessage* hako_create_empty_pdu_TFMessage(int heap_size)
{
    int total_size = sizeof(Hako_TFMessage) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_TFMessage));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_TFMessage) + sizeof(HakoPduMetaDataType);
    return (Hako_TFMessage*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_ */
