#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_LiDARScanResponse_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_LiDARScanResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_LiDARScanResponse.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/li_d_a_r_scan_response.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "sensor_msgs/pdu_ctype_conv_PointCloud2.hpp"
#include "sensor_msgs/pdu_ctype_conv_PointField.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_LiDARScanResponse(const char* heap_ptr, Hako_LiDARScanResponse &src, drone_srv_msgs::msg::LiDARScanResponse &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.ok, dst.ok);
    // Struct convert
    _pdu2ros_PointCloud2(heap_ptr, src.point_cloud, dst.point_cloud);
    // Struct convert
    _pdu2ros_Pose(heap_ptr, src.lidar_pose, dst.lidar_pose);
    // string convertor
    dst.message = (const char*)src.message;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_LiDARScanResponse(Hako_LiDARScanResponse &src, drone_srv_msgs::msg::LiDARScanResponse &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_LiDARScanResponse((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_LiDARScanResponse(drone_srv_msgs::msg::LiDARScanResponse &src, Hako_LiDARScanResponse &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.ok, dst.ok);
        // struct convert
        _ros2pdu_PointCloud2(src.point_cloud, dst.point_cloud, dynamic_memory);
        // struct convert
        _ros2pdu_Pose(src.lidar_pose, dst.lidar_pose, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.message, src.message.length(),
            dst.message, M_ARRAY_SIZE(Hako_LiDARScanResponse, char, message));
        dst.message[src.message.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_LiDARScanResponse(drone_srv_msgs::msg::LiDARScanResponse &src, Hako_LiDARScanResponse** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_LiDARScanResponse out;
    if (!_ros2pdu_LiDARScanResponse(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_LiDARScanResponse), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_LiDARScanResponse));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_LiDARScanResponse*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_LiDARScanResponse* hako_create_empty_pdu_LiDARScanResponse(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_LiDARScanResponse), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_LiDARScanResponse*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_LiDARScanResponse_HPP_ */
