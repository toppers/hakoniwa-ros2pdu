#ifndef _pdu_ctype_drone_srv_msgs_DroneLandRequest_H_
#define _pdu_ctype_drone_srv_msgs_DroneLandRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
} Hako_DroneLandRequest;

#endif /* _pdu_ctype_drone_srv_msgs_DroneLandRequest_H_ */
