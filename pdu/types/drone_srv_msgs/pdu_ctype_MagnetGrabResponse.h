#ifndef _pdu_ctype_drone_srv_msgs_MagnetGrabResponse_H_
#define _pdu_ctype_drone_srv_msgs_MagnetGrabResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool ok;
        Hako_bool magnet_on;
        Hako_bool contact_on;
        char message[HAKO_STRING_SIZE];
} Hako_MagnetGrabResponse;

#endif /* _pdu_ctype_drone_srv_msgs_MagnetGrabResponse_H_ */
