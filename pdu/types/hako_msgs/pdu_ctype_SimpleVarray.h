#ifndef _pdu_ctype_hako_msgs_SimpleVarray_H_
#define _pdu_ctype_hako_msgs_SimpleVarray_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        // int8 data[]
        int _data_len;
        int _data_off;
        Hako_int8 fixed_array[10];
        Hako_int32 p_mem1;
} Hako_SimpleVarray;

#endif /* _pdu_ctype_hako_msgs_SimpleVarray_H_ */
