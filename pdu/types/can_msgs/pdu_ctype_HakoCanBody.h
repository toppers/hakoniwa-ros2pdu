#ifndef _pdu_ctype_can_msgs_HakoCanBody_H_
#define _pdu_ctype_can_msgs_HakoCanBody_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint8 data[8];
} Hako_HakoCanBody;

#endif /* _pdu_ctype_can_msgs_HakoCanBody_H_ */
