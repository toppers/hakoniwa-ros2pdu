#ifndef _pdu_ctype_hako_msgs_MonitorCameraData_H_
#define _pdu_ctype_hako_msgs_MonitorCameraData_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "sensor_msgs/pdu_ctype_CompressedImage.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_int32 request_id;
        Hako_int32 image_data_length;
        Hako_CompressedImage image;
} Hako_MonitorCameraData;

#endif /* _pdu_ctype_hako_msgs_MonitorCameraData_H_ */
