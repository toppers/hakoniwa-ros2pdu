#ifndef _pdu_ctype_sensor_msgs_CameraInfo_H_
#define _pdu_ctype_sensor_msgs_CameraInfo_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "sensor_msgs/pdu_ctype_RegionOfInterest.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        char distortion_model[HAKO_STRING_SIZE];
        // float64 d[]
        int _d_len;
        int _d_off;
        Hako_float64 k[9];
        Hako_float64 r[9];
        Hako_float64 p[12];
        Hako_uint32 binning_x;
        Hako_uint32 binning_y;
        Hako_RegionOfInterest roi;
} Hako_CameraInfo;

#endif /* _pdu_ctype_sensor_msgs_CameraInfo_H_ */
