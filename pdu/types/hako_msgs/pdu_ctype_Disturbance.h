#ifndef _pdu_ctype_hako_msgs_Disturbance_H_
#define _pdu_ctype_hako_msgs_Disturbance_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "hako_msgs/pdu_ctype_DisturbanceTemperature.h"
#include "hako_msgs/pdu_ctype_DisturbanceWind.h"

typedef struct {
        Hako_DisturbanceTemperature d_temp;
        Hako_DisturbanceWind d_wind;
} Hako_Disturbance;

#endif /* _pdu_ctype_hako_msgs_Disturbance_H_ */
