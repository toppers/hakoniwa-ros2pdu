#ifndef _pdu_ctype_hako_msgs_HakoCameraInfo_H_
#define _pdu_ctype_hako_msgs_HakoCameraInfo_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_int32 request_id;
        Hako_Vector3 angle;
} Hako_HakoCameraInfo;

#endif /* _pdu_ctype_hako_msgs_HakoCameraInfo_H_ */
