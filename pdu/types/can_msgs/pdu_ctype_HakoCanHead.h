#ifndef _pdu_ctype_can_msgs_HakoCanHead_H_
#define _pdu_ctype_can_msgs_HakoCanHead_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 channel;
        Hako_uint32 ide;
        Hako_uint32 rtr;
        Hako_uint32 dlc;
        Hako_uint32 canid;
} Hako_HakoCanHead;

#endif /* _pdu_ctype_can_msgs_HakoCanHead_H_ */
