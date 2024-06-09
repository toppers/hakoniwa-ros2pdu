#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_color_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Ev3PduColorSensor(const char* varray_ptr, Hako_Ev3PduColorSensor &src, ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.color, dst.color);
    // primitive convert
    hako_convert_pdu2ros(src.reflect, dst.reflect);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_r, dst.rgb_r);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_g, dst.rgb_g);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_b, dst.rgb_b);
    return 0;
}

static inline int hako_convert_pdu2ros_Ev3PduColorSensor(Hako_Ev3PduColorSensor &src, ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduColorSensor));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Ev3PduColorSensor) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Ev3PduColorSensor(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Ev3PduColorSensor(ev3_msgs::msg::Ev3PduColorSensor &src, Hako_Ev3PduColorSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.color, dst.color);
        // primitive convert
        hako_convert_ros2pdu(src.reflect, dst.reflect);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_r, dst.rgb_r);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_g, dst.rgb_g);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_b, dst.rgb_b);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Ev3PduColorSensor(ev3_msgs::msg::Ev3PduColorSensor &src, Hako_Ev3PduColorSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduColorSensor out;
    if (!_ros2pdu_Ev3PduColorSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Ev3PduColorSensor) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduColorSensor));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduColorSensor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduColorSensor) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Ev3PduColorSensor*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_ */
