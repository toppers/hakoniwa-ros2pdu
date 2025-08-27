#ifndef _pdu_cpptype_drone_srv_msgs_LiDARScanResponsePacket_HPP_
#define _pdu_cpptype_drone_srv_msgs_LiDARScanResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "drone_srv_msgs/pdu_cpptype_LiDARScanResponse.hpp"
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "hako_srv_msgs/pdu_cpptype_ServiceResponseHeader.hpp"
#include "sensor_msgs/pdu_cpptype_PointCloud2.hpp"
#include "sensor_msgs/pdu_cpptype_PointField.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_ServiceResponseHeader header;
        HakoCpp_LiDARScanResponse body;
} HakoCpp_LiDARScanResponsePacket;

#endif /* _pdu_cpptype_drone_srv_msgs_LiDARScanResponsePacket_HPP_ */
