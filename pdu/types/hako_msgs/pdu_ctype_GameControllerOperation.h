#ifndef _pdu_ctype_hako_msgs_GameControllerOperation_H_
#define _pdu_ctype_hako_msgs_GameControllerOperation_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_float64 axis[6];
        Hako_bool button[15];
} Hako_GameControllerOperation;

#endif /* _pdu_ctype_hako_msgs_GameControllerOperation_H_ */
