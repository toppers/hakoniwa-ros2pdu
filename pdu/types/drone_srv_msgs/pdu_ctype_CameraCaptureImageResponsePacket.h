#ifndef _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_
#define _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "drone_srv_msgs/pdu_ctype_CameraCaptureImageResponse.h"
#include "hako_srv_msgs/pdu_ctype_ServiceResponseHeader.h"
#include "sensor_msgs/pdu_ctype_CompressedImage.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        Hako_ServiceResponseHeader header;
        Hako_CameraCaptureImageResponse body;
} Hako_CameraCaptureImageResponsePacket;

#endif /* _pdu_ctype_drone_srv_msgs_CameraCaptureImageResponsePacket_H_ */
