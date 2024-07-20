#ifndef _pdu_cpptype_hako_msgs_GameControllerOperation_HPP_
#define _pdu_cpptype_hako_msgs_GameControllerOperation_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::array<Hako_float64, 6> axis;
        std::array<Hako_bool, 15> button;
} HakoCpp_GameControllerOperation;

#endif /* _pdu_cpptype_hako_msgs_GameControllerOperation_HPP_ */
