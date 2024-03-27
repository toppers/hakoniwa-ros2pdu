#ifndef _pdu_ctype_hako_msgs_HakoCmdHeader_H_
#define _pdu_ctype_hako_msgs_HakoCmdHeader_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_bool request;
        Hako_bool result;
        Hako_int32 result_code;
} Hako_HakoCmdHeader;

#endif /* _pdu_ctype_hako_msgs_HakoCmdHeader_H_ */
