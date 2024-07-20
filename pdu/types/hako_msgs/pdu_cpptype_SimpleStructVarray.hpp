#ifndef _pdu_cpptype_hako_msgs_SimpleStructVarray_HPP_
#define _pdu_cpptype_hako_msgs_SimpleStructVarray_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_msgs/pdu_cpptype_SimpleVarray.hpp"

typedef struct {
        Hako_int32 aaa;
        std::array<std::string, 2> fixed_str;
        std::vector<std::string> varray_str;
        std::array<HakoCpp_SimpleVarray, 5> fixed_array;
        std::vector<HakoCpp_SimpleVarray> data;
} HakoCpp_SimpleStructVarray;

#endif /* _pdu_cpptype_hako_msgs_SimpleStructVarray_HPP_ */
