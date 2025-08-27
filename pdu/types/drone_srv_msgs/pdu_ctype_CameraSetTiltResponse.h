#ifndef _pdu_ctype_drone_srv_msgs_CameraSetTiltResponse_H_
#define _pdu_ctype_drone_srv_msgs_CameraSetTiltResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool ok;
        char message[HAKO_STRING_SIZE];
} Hako_CameraSetTiltResponse;

#endif /* _pdu_ctype_drone_srv_msgs_CameraSetTiltResponse_H_ */
