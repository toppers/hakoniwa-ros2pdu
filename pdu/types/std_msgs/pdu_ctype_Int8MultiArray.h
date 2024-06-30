#ifndef _pdu_ctype_std_msgs_Int8MultiArray_H_
#define _pdu_ctype_std_msgs_Int8MultiArray_H_

#include "pdu_primitive_ctypes.h"
#include "std_msgs/pdu_ctype_MultiArrayDimension.h"
#include "std_msgs/pdu_ctype_MultiArrayLayout.h"

typedef struct {
        Hako_MultiArrayLayout layout;
        // int8 data[]
        int _data_len;
        int _data_off;
} Hako_Int8MultiArray;

#endif /* _pdu_ctype_std_msgs_Int8MultiArray_H_ */
