#ifndef _pdu_ctype_drone_srv_msgs_LiDARScanRequest_H_
#define _pdu_ctype_drone_srv_msgs_LiDARScanRequest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char drone_name[HAKO_STRING_SIZE];
} Hako_LiDARScanRequest;

#endif /* _pdu_ctype_drone_srv_msgs_LiDARScanRequest_H_ */
