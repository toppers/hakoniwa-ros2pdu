#ifndef _pdu_ctype_nav_msgs_Odometry_H_
#define _pdu_ctype_nav_msgs_Odometry_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Point.h"
#include "geometry_msgs/pdu_ctype_Pose.h"
#include "geometry_msgs/pdu_ctype_PoseWithCovariance.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "geometry_msgs/pdu_ctype_Twist.h"
#include "geometry_msgs/pdu_ctype_TwistWithCovariance.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        char child_frame_id[HAKO_STRING_SIZE];
        Hako_PoseWithCovariance pose;
        Hako_TwistWithCovariance twist;
} Hako_Odometry;

#endif /* _pdu_ctype_nav_msgs_Odometry_H_ */
