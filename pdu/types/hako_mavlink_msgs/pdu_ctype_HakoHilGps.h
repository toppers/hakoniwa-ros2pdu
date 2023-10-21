#ifndef _pdu_ctype_hako_mavlink_msgs_HakoHilGps_H_
#define _pdu_ctype_hako_mavlink_msgs_HakoHilGps_H_

#include "pdu_primitive_ctypes.h"

typedef struct {
        Hako_uint64 time_usec;
        Hako_int32 lat;
        Hako_int32 lon;
        Hako_int32 alt;
        Hako_uint16 eph;
        Hako_uint16 epv;
        Hako_uint16 vel;
        Hako_int16 vn;
        Hako_int16 ve;
        Hako_int16 vd;
        Hako_uint16 cog;
        Hako_uint8 satellites_visible;
        Hako_uint8 id;
        Hako_uint8 yaw;
        Hako_uint8 fix_type;
} Hako_HakoHilGps;

#endif /* _pdu_ctype_hako_mavlink_msgs_HakoHilGps_H_ */
