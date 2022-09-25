#ifndef _pdu_ctype_ev3_msgs_Ev3PduActuatorHeader_H_
#define _pdu_ctype_ev3_msgs_Ev3PduActuatorHeader_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char name[HAKO_STRING_SIZE];
        Hako_uint32 version;
        Hako_int64 asset_time;
        Hako_uint32 ext_off;
        Hako_uint32 ext_size;
} Hako_Ev3PduActuatorHeader;

#endif /* _pdu_ctype_ev3_msgs_Ev3PduActuatorHeader_H_ */
