#ifndef _pdu_ctype_hako_msgs_DroneStatus_H_
#define _pdu_ctype_hako_msgs_DroneStatus_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_int32 flight_mode;
        Hako_int32 internal_state;
        Hako_Vector3 propeller_wind;
        Hako_int32 collided_counts;
} Hako_DroneStatus;

#endif /* _pdu_ctype_hako_msgs_DroneStatus_H_ */
