#ifndef _pdu_ctype_hako_msgs_HakoCmdCameraMove_H_
#define _pdu_ctype_hako_msgs_HakoCmdCameraMove_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "hako_msgs/pdu_ctype_HakoCmdHeader.h"

typedef struct {
        Hako_HakoCmdHeader header;
        Hako_int32 request_id;
        Hako_Vector3 angle;
} Hako_HakoCmdCameraMove;

#endif /* _pdu_ctype_hako_msgs_HakoCmdCameraMove_H_ */
