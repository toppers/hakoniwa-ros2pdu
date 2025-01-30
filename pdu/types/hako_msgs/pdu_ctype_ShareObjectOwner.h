#ifndef _pdu_ctype_hako_msgs_ShareObjectOwner_H_
#define _pdu_ctype_hako_msgs_ShareObjectOwner_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Twist.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        char object_name[HAKO_STRING_SIZE];
        Hako_uint32 owner_id;
        Hako_uint64 last_update;
        Hako_Twist pos;
} Hako_ShareObjectOwner;

#endif /* _pdu_ctype_hako_msgs_ShareObjectOwner_H_ */
