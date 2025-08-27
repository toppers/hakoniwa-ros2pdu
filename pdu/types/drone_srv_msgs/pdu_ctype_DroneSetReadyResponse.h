#ifndef _pdu_ctype_drone_srv_msgs_DroneSetReadyResponse_H_
#define _pdu_ctype_drone_srv_msgs_DroneSetReadyResponse_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool ok;
        char message[HAKO_STRING_SIZE];
} Hako_DroneSetReadyResponse;

#endif /* _pdu_ctype_drone_srv_msgs_DroneSetReadyResponse_H_ */
