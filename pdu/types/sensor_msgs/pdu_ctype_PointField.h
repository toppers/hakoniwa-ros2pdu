#ifndef _pdu_ctype_sensor_msgs_PointField_H_
#define _pdu_ctype_sensor_msgs_PointField_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        char name[HAKO_STRING_SIZE];
        Hako_uint32 offset;
        Hako_uint8 datatype;
        Hako_uint32 count;
} Hako_PointField;

#endif /* _pdu_ctype_sensor_msgs_PointField_H_ */
