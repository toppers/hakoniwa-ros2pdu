#ifndef _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "pico_msgs/pdu_ctype_LightSensor.h"
/*
 * Dependent ros data
 */
#include "pico_msgs/msg/light_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_LightSensor(const char* varray_ptr, Hako_LightSensor &src, pico_msgs::msg::LightSensor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.forward_r, dst.forward_r);
    // primitive convert
    hako_convert_pdu2ros(src.forward_l, dst.forward_l);
    // primitive convert
    hako_convert_pdu2ros(src.left, dst.left);
    // primitive convert
    hako_convert_pdu2ros(src.right, dst.right);
    return 0;
}

static inline int hako_convert_pdu2ros_LightSensor(Hako_LightSensor &src, pico_msgs::msg::LightSensor &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LightSensor));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_LightSensor) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_LightSensor(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_LightSensor(pico_msgs::msg::LightSensor &src, Hako_LightSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.forward_r, dst.forward_r);
        // primitive convert
        hako_convert_ros2pdu(src.forward_l, dst.forward_l);
        // primitive convert
        hako_convert_ros2pdu(src.left, dst.left);
        // primitive convert
        hako_convert_ros2pdu(src.right, dst.right);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_LightSensor(pico_msgs::msg::LightSensor &src, Hako_LightSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_LightSensor out;
    if (!_ros2pdu_LightSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_LightSensor) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_LightSensor));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LightSensor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_LightSensor) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_LightSensor*)base_ptr;
    return total_size;
}
static inline Hako_LightSensor* hako_create_empty_pdu_LightSensor(int heap_size)
{
    int total_size = sizeof(Hako_LightSensor) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_LightSensor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_LightSensor) + sizeof(HakoPduMetaDataType);
    return (Hako_LightSensor*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_ */
