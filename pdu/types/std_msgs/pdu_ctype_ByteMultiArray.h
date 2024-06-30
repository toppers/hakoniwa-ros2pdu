#ifndef _pdu_ctype_std_msgs_ByteMultiArray_H_
#define _pdu_ctype_std_msgs_ByteMultiArray_H_

#include "pdu_primitive_ctypes.h"
#include "std_msgs/pdu_ctype_MultiArrayDimension.h"
#include "std_msgs/pdu_ctype_MultiArrayLayout.h"

typedef struct {
        Hako_MultiArrayLayout layout;
        // byte data[]
        int _data_len;
        int _data_off;
} Hako_ByteMultiArray;

#endif /* _pdu_ctype_std_msgs_ByteMultiArray_H_ */
