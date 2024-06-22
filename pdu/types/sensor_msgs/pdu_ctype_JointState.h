#ifndef _pdu_ctype_sensor_msgs_JointState_H_
#define _pdu_ctype_sensor_msgs_JointState_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        // string name[]
        int _name_len;
        int _name_off;
        // float64 position[]
        int _position_len;
        int _position_off;
        // float64 velocity[]
        int _velocity_len;
        int _velocity_off;
        // float64 effort[]
        int _effort_len;
        int _effort_off;
} Hako_JointState;

#endif /* _pdu_ctype_sensor_msgs_JointState_H_ */
