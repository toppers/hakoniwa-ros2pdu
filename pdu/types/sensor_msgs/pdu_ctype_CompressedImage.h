#ifndef _pdu_ctype_sensor_msgs_CompressedImage_H_
#define _pdu_ctype_sensor_msgs_CompressedImage_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_Header header;
        char format[HAKO_STRING_SIZE];
        // uint8 data[]
        int _data_len;
        int _data_off;
} Hako_CompressedImage;

#endif /* _pdu_ctype_sensor_msgs_CompressedImage_H_ */
