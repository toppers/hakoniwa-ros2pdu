#ifndef _pdu_ctype_tf2_msgs_TFMessage_H_
#define _pdu_ctype_tf2_msgs_TFMessage_H_

#include "pdu_primitive_ctypes.h"
#include "builtin_interfaces/pdu_ctype_Time.h"
#include "geometry_msgs/pdu_ctype_Quaternion.h"
#include "geometry_msgs/pdu_ctype_Transform.h"
#include "geometry_msgs/pdu_ctype_TransformStamped.h"
#include "geometry_msgs/pdu_ctype_Vector3.h"
#include "std_msgs/pdu_ctype_Header.h"

typedef struct {
        // TransformStamped transforms[]
        int _transforms_len;
        int _transforms_off;
} Hako_TFMessage;

#endif /* _pdu_ctype_tf2_msgs_TFMessage_H_ */
