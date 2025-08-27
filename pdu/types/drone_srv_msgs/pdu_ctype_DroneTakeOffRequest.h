#ifndef _pdu_ctype_drone_srv_msgs_DroneTakeOffRequest_H_
#define _pdu_ctype_drone_srv_msgs_DroneTakeOffRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_float64 alt_m;
        char drone_name[HAKO_STRING_SIZE];
} Hako_DroneTakeOffRequest;

#endif /* _pdu_ctype_drone_srv_msgs_DroneTakeOffRequest_H_ */
