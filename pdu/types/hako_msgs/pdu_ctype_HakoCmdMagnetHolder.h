#ifndef _pdu_ctype_hako_msgs_HakoCmdMagnetHolder_H_
#define _pdu_ctype_hako_msgs_HakoCmdMagnetHolder_H_

#include "pdu_primitive_ctypes.h"
#include "hako_msgs/pdu_ctype_HakoCmdHeader.h"

typedef struct {
        Hako_HakoCmdHeader header;
        Hako_bool magnet_on;
} Hako_HakoCmdMagnetHolder;

#endif /* _pdu_ctype_hako_msgs_HakoCmdMagnetHolder_H_ */
