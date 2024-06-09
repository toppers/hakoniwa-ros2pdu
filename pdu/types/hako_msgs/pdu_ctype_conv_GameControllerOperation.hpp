#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_GameControllerOperation.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/game_controller_operation.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_GameControllerOperation_axis(const char* varray_ptr, Hako_GameControllerOperation &src, hako_msgs::msg::GameControllerOperation &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 4; ++i) {
        hako_convert_pdu2ros(src.axis[i], dst.axis[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_GameControllerOperation_button(const char* varray_ptr, Hako_GameControllerOperation &src, hako_msgs::msg::GameControllerOperation &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 4; ++i) {
        hako_convert_pdu2ros(src.button[i], dst.button[i]);
    }
    return 0;
}

static inline int _pdu2ros_GameControllerOperation(const char* varray_ptr, Hako_GameControllerOperation &src, hako_msgs::msg::GameControllerOperation &dst)
{
    // primitive array convertor
    _pdu2ros_primitive_array_GameControllerOperation_axis(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_GameControllerOperation_button(varray_ptr, src, dst);
    return 0;
}

static inline int hako_convert_pdu2ros_GameControllerOperation(Hako_GameControllerOperation &src, hako_msgs::msg::GameControllerOperation &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_GameControllerOperation));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_GameControllerOperation) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_GameControllerOperation(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_GameControllerOperation_axis(hako_msgs::msg::GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 4
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.axis, src.axis.size(),
        dst.axis, M_ARRAY_SIZE(Hako_GameControllerOperation, Hako_float64, axis));
    return true;
}
static inline bool _ros2pdu_primitive_array_GameControllerOperation_button(hako_msgs::msg::GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 4
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.button, src.button.size(),
        dst.button, M_ARRAY_SIZE(Hako_GameControllerOperation, Hako_bool, button));
    return true;
}

static inline bool _ros2pdu_GameControllerOperation(hako_msgs::msg::GameControllerOperation &src, Hako_GameControllerOperation &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //primitive array copy
        _ros2pdu_primitive_array_GameControllerOperation_axis(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_GameControllerOperation_button(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_GameControllerOperation(hako_msgs::msg::GameControllerOperation &src, Hako_GameControllerOperation** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_GameControllerOperation out;
    if (!_ros2pdu_GameControllerOperation(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_GameControllerOperation) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_GameControllerOperation));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_GameControllerOperation));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_GameControllerOperation) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_GameControllerOperation*)base_ptr;
    return total_size;
}
static inline Hako_GameControllerOperation* hako_create_empty_pdu_GameControllerOperation(int heap_size)
{
    int total_size = sizeof(Hako_GameControllerOperation) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_GameControllerOperation));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_GameControllerOperation) + sizeof(HakoPduMetaDataType);
    return (Hako_GameControllerOperation*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_ */
