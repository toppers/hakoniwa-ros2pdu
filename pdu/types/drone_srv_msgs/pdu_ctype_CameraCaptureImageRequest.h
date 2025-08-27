#ifndef _pdu_ctype_drone_srv_msgs_CameraCaptureImageRequest_H_
#define _pdu_ctype_drone_srv_msgs_CameraCaptureImageRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
        char image_type[HAKO_STRING_SIZE];
} Hako_CameraCaptureImageRequest;

#endif /* _pdu_ctype_drone_srv_msgs_CameraCaptureImageRequest_H_ */
