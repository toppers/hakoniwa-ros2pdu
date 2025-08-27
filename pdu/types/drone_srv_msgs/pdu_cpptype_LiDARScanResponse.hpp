#ifndef _pdu_cpptype_drone_srv_msgs_LiDARScanResponse_HPP_
#define _pdu_cpptype_drone_srv_msgs_LiDARScanResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Point.hpp"
#include "geometry_msgs/pdu_cpptype_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "sensor_msgs/pdu_cpptype_PointCloud2.hpp"
#include "sensor_msgs/pdu_cpptype_PointField.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        Hako_bool ok;
        HakoCpp_PointCloud2 point_cloud;
        HakoCpp_Pose lidar_pose;
        std::string message;
} HakoCpp_LiDARScanResponse;

#endif /* _pdu_cpptype_drone_srv_msgs_LiDARScanResponse_HPP_ */
