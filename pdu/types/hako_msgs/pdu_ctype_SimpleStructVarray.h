#ifndef _pdu_ctype_hako_msgs_SimpleStructVarray_H_
#define _pdu_ctype_hako_msgs_SimpleStructVarray_H_

#include "pdu_primitive_ctypes.h"
#include "hako_msgs/pdu_ctype_SimpleVarray.h"

typedef struct {
        Hako_int32 aaa;
        Hako_cstring fixed_str[2];
        // string varray_str[]
        int _varray_str_len;
        int _varray_str_off;
        Hako_SimpleVarray fixed_array[5];
        // SimpleVarray data[]
        int _data_len;
        int _data_off;
} Hako_SimpleStructVarray;

#endif /* _pdu_ctype_hako_msgs_SimpleStructVarray_H_ */
