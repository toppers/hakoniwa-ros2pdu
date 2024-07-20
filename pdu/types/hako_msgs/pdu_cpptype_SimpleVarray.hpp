#ifndef _pdu_cpptype_hako_msgs_SimpleVarray_HPP_
#define _pdu_cpptype_hako_msgs_SimpleVarray_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        std::vector<Hako_int8> data;
        std::array<Hako_int8, 10> fixed_array;
        Hako_int32 p_mem1;
} HakoCpp_SimpleVarray;

#endif /* _pdu_cpptype_hako_msgs_SimpleVarray_HPP_ */
