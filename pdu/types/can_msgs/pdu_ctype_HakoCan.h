#ifndef _pdu_ctype_can_msgs_HakoCan_H_
#define _pdu_ctype_can_msgs_HakoCan_H_

#include "pdu_primitive_ctypes.h"
#include "can_msgs/pdu_ctype_HakoCanBody.h"
#include "can_msgs/pdu_ctype_HakoCanHead.h"

typedef struct {
        Hako_HakoCanHead head;
        Hako_HakoCanBody body;
} Hako_HakoCan;

#endif /* _pdu_ctype_can_msgs_HakoCan_H_ */
