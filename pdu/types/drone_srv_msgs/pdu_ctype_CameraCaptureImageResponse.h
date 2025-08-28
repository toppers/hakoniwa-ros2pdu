#ifndef _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_
#define _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool ok;
        // uint8 data[]
        int _data_len;
        int _data_off;
        char message[HAKO_STRING_SIZE];
} Hako_CameraCaptureImageResponse;

#endif /* _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponse_H_ */
