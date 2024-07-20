#ifndef _pdu_cpptype_ev3_msgs_Ev3PduActuatorHeader_HPP_
#define _pdu_cpptype_ev3_msgs_Ev3PduActuatorHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::string name;
        Hako_uint32 version;
        Hako_int64 asset_time;
        Hako_uint32 ext_off;
        Hako_uint32 ext_size;
} HakoCpp_Ev3PduActuatorHeader;

#endif /* _pdu_cpptype_ev3_msgs_Ev3PduActuatorHeader_HPP_ */
