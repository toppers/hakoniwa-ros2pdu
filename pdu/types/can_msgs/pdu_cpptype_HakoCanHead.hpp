#ifndef _pdu_cpptype_can_msgs_HakoCanHead_HPP_
#define _pdu_cpptype_can_msgs_HakoCanHead_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_uint32 channel;
        Hako_uint32 ide;
        Hako_uint32 rtr;
        Hako_uint32 dlc;
        Hako_uint32 canid;
} HakoCpp_HakoCanHead;

#endif /* _pdu_cpptype_can_msgs_HakoCanHead_HPP_ */
