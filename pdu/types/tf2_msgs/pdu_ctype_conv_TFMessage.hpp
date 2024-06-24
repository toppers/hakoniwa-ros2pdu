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
static inline int _pdu2ros_struct_array_TFMessage_transforms(const char* heap_ptr, Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    // Convert using len and off
    int offset = src._transforms_off;
    int length = src._transforms_len;
    if (length > 0) {
        dst.transforms.resize(length);
        Hako_TransformStamped *temp_struct_ptr = (Hako_TransformStamped *)(heap_ptr + offset);
        for (int i = 0; i < length; ++i) {
            _pdu2ros_TransformStamped(heap_ptr, *temp_struct_ptr, dst.transforms[i]);
            temp_struct_ptr++;
        }
    }
    return 0;
}

static inline int _pdu2ros_TFMessage(const char* heap_ptr, Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    // struct array convertor
    _pdu2ros_struct_array_TFMessage_transforms(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_TFMessage(Hako_TFMessage &src, tf2_msgs::msg::TFMessage &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_TFMessage((char*)heap_ptr, src, dst);
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
    dst._transforms_len = src.transforms.size();
    if (dst._transforms_len > 0) {
        Hako_TransformStamped* temp_struct_ptr = (Hako_TransformStamped*)dynamic_memory.allocate(dst._transforms_len, sizeof(Hako_TransformStamped));
        dst._transforms_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._transforms_len; ++i) {
            _ros2pdu_TransformStamped(src.transforms[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._transforms_off = dynamic_memory.get_total_size();
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
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_TFMessage(tf2_msgs::msg::TFMessage &src, Hako_TFMessage** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TFMessage out;
    if (!_ros2pdu_TFMessage(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_TFMessage), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TFMessage));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_TFMessage*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_TFMessage* hako_create_empty_pdu_TFMessage(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_TFMessage), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_TFMessage*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_tf2_msgs_TFMessage_HPP_ */
