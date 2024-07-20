#ifndef _pdu_cpptype_can_msgs_HakoCanBody_HPP_
#define _pdu_cpptype_can_msgs_HakoCanBody_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::array<Hako_uint8, 8> data;
} HakoCpp_HakoCanBody;

#endif /* _pdu_cpptype_can_msgs_HakoCanBody_HPP_ */
