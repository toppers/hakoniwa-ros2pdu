#ifndef _pdu_ctype_sensor_msgs_RegionOfInterest_H_
#define _pdu_ctype_sensor_msgs_RegionOfInterest_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint32 x_offset;
        Hako_uint32 y_offset;
        Hako_uint32 height;
        Hako_uint32 width;
        Hako_bool do_rectify;
} Hako_RegionOfInterest;

#endif /* _pdu_ctype_sensor_msgs_RegionOfInterest_H_ */
