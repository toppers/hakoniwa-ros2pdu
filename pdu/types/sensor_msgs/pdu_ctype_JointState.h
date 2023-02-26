#ifndef _pdu_ctype_sensor_msgs_JointState_H_
#define _pdu_ctype_sensor_msgs_JointState_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header    header;
        Hako_cstring name[2];
        Hako_float64 position[2];
        Hako_float64 velocity[2];
        Hako_float64 effort[2];
} Hako_JointState;

#endif /* _pdu_ctype_sensor_msgs_JointState_H_ */
