#ifndef _pdu_ctype_sensor_msgs_Image_H_
#define _pdu_ctype_sensor_msgs_Image_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        Hako_uint32 height;
        Hako_uint32 width;
        char encoding[HAKO_STRING_SIZE];
        Hako_uint8 is_bigendian;
        Hako_uint32 step;
        // uint8 data[]
        int _data_len;
        int _data_off;
} Hako_Image;

#endif /* _pdu_ctype_sensor_msgs_Image_H_ */
