#ifndef _pdu_ctype_sensor_msgs_LaserScan_H_
#define _pdu_ctype_sensor_msgs_LaserScan_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_float32 angle_min;
        Hako_float32 angle_max;
        Hako_float32 angle_increment;
        Hako_float32 time_increment;
        Hako_float32 scan_time;
        Hako_float32 range_min;
        Hako_float32 range_max;
        // float32 ranges[]
        int _ranges_len;
        int _ranges_off;
        // float32 intensities[]
        int _intensities_len;
        int _intensities_off;
} Hako_LaserScan;

#endif /* _pdu_ctype_sensor_msgs_LaserScan_H_ */
