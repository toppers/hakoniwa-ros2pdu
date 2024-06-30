#ifndef _pdu_ctype_std_msgs_MultiArrayDimension_H_
#define _pdu_ctype_std_msgs_MultiArrayDimension_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char label[HAKO_STRING_SIZE];
        Hako_uint32 size;
        Hako_uint32 stride;
} Hako_MultiArrayDimension;

#endif /* _pdu_ctype_std_msgs_MultiArrayDimension_H_ */
