#ifndef _pdu_ctype_sensor_msgs_PointCloud2_H_
#define _pdu_ctype_sensor_msgs_PointCloud2_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "sensor_msgs/pdu_ctype_PointField.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        Hako_PointField fields[4];
        Hako_bool is_bigendian;
        Hako_uint32 point_step;
        Hako_uint32 row_step;
        Hako_uint8 data[176656];
        Hako_bool is_dense;
} Hako_PointCloud2;

#endif /* _pdu_ctype_sensor_msgs_PointCloud2_H_ */
