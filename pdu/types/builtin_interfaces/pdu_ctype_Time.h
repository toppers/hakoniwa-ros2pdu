#ifndef _pdu_ctype_builtin_interfaces_Time_H_
#define _pdu_ctype_builtin_interfaces_Time_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_int32 sec;
        Hako_uint32 nanosec;
} Hako_Time;

#endif /* _pdu_ctype_builtin_interfaces_Time_H_ */
