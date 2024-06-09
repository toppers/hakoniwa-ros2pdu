#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduMotor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_motor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Ev3PduMotor(const char* varray_ptr, Hako_Ev3PduMotor &src, ev3_msgs::msg::Ev3PduMotor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.power, dst.power);
    // primitive convert
    hako_convert_pdu2ros(src.stop, dst.stop);
    // primitive convert
    hako_convert_pdu2ros(src.reset_angle, dst.reset_angle);
    return 0;
}

static inline int hako_convert_pdu2ros_Ev3PduMotor(Hako_Ev3PduMotor &src, ev3_msgs::msg::Ev3PduMotor &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduMotor));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Ev3PduMotor) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Ev3PduMotor(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Ev3PduMotor(ev3_msgs::msg::Ev3PduMotor &src, Hako_Ev3PduMotor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.power, dst.power);
        // primitive convert
        hako_convert_ros2pdu(src.stop, dst.stop);
        // primitive convert
        hako_convert_ros2pdu(src.reset_angle, dst.reset_angle);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Ev3PduMotor(ev3_msgs::msg::Ev3PduMotor &src, Hako_Ev3PduMotor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduMotor out;
    if (!_ros2pdu_Ev3PduMotor(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Ev3PduMotor) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduMotor));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduMotor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduMotor) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Ev3PduMotor*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduMotor_HPP_ */
