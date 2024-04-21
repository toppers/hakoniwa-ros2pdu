#ifndef _pdu_ctype_hako_msgs_GameControllerOperation_H_
#define _pdu_ctype_hako_msgs_GameControllerOperation_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_float64 axis[3];
        Hako_bool button[4];
} Hako_GameControllerOperation;

#endif /* _pdu_ctype_hako_msgs_GameControllerOperation_H_ */
