#ifndef _pdu_ctype_satelite_msgs_SateliteImu_H_
#define _pdu_ctype_satelite_msgs_SateliteImu_H_

#include "pdu_primitive_ctypes.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"

typedef struct {
        Hako_Vector3    acc;
        Hako_Vector3    gyro;
        Hako_Vector3    mag;
} Hako_SateliteImu;

#endif /* _pdu_ctype_satelite_msgs_SateliteImu_H_ */
