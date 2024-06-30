#ifndef _pdu_ctype_std_msgs_MultiArrayLayout_H_
#define _pdu_ctype_std_msgs_MultiArrayLayout_H_

#include "pdu_primitive_ctypes.h"
#include "std_msgs/pdu_ctype_MultiArrayDimension.h"

typedef struct {
        // MultiArrayDimension dim[]
        int _dim_len;
        int _dim_off;
        Hako_uint32 data_offset;
} Hako_MultiArrayLayout;

#endif /* _pdu_ctype_std_msgs_MultiArrayLayout_H_ */
