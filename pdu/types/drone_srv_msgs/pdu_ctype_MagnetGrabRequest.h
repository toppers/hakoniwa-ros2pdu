#ifndef _pdu_ctype_drone_srv_msgs_MagnetGrabRequest_H_
#define _pdu_ctype_drone_srv_msgs_MagnetGrabRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
        Hako_bool grab_on;
        Hako_float32 timeout_sec;
} Hako_MagnetGrabRequest;

#endif /* _pdu_ctype_drone_srv_msgs_MagnetGrabRequest_H_ */
