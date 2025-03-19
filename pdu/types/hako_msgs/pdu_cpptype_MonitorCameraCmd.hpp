#ifndef _pdu_cpptype_hako_msgs_MonitorCameraCmd_HPP_
#define _pdu_cpptype_hako_msgs_MonitorCameraCmd_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_msgs/pdu_cpptype_HakoCmdHeader.hpp"

typedef struct {
        HakoCpp_HakoCmdHeader header;
        Hako_int32 request_id;
        Hako_int32 encode_type;
        Hako_int32 request_type;
} HakoCpp_MonitorCameraCmd;

#endif /* _pdu_cpptype_hako_msgs_MonitorCameraCmd_HPP_ */
