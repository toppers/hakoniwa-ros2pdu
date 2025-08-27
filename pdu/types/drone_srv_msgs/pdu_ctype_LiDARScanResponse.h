#ifndef _pdu_ctype_drone_srv_msgs_LiDARScanResponse_H_
#define _pdu_ctype_drone_srv_msgs_LiDARScanResponse_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Pose.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
#include "sensor_msgs/pdu_ctype_PointField.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_bool ok;
        Hako_PointCloud2 point_cloud;
        Hako_Pose lidar_pose;
        char message[HAKO_STRING_SIZE];
} Hako_LiDARScanResponse;

#endif /* _pdu_ctype_drone_srv_msgs_LiDARScanResponse_H_ */
