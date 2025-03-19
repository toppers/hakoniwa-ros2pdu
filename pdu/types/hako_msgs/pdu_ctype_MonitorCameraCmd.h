#ifndef _pdu_ctype_hako_msgs_MonitorCameraCmd_H_
#define _pdu_ctype_hako_msgs_MonitorCameraCmd_H_

#include "pdu_primitive_ctypes.h"
#include "hako_msgs/pdu_ctype_HakoCmdHeader.h"

typedef struct {
        Hako_HakoCmdHeader header;
        Hako_int32 request_id;
        Hako_int32 encode_type;
        Hako_int32 request_type;
} Hako_MonitorCameraCmd;

#endif /* _pdu_ctype_hako_msgs_MonitorCameraCmd_H_ */
