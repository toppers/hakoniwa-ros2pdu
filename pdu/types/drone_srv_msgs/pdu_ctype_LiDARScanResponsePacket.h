#ifndef _pdu_ctype_drone_srv_msgs_LiDARScanResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_LiDARScanResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "drone_srv_msgs/pdu_ctype_LiDARScanResponse.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Pose.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
#include "sensor_msgs/pdu_ctype_PointField.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_LiDARScanResponse body;
} Hako_LiDARScanResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_LiDARScanResponsePacket_H_ */
