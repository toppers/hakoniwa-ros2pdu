#ifndef _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_
#define _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "sensor_msgs/pdu_ctype_CompressedImage.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_bool ok;
        Hako_CompressedImage image;
        char message[HAKO_STRING_SIZE];
} Hako_CameraCaptureImageResponse;

#endif /* _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_ */
