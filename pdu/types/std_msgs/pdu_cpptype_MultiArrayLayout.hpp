#ifndef _pdu_cpptype_std_msgs_MultiArrayLayout_HPP_
#define _pdu_cpptype_std_msgs_MultiArrayLayout_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "std_msgs/pdu_cpptype_MultiArrayDimension.hpp"

typedef struct {
        std::vector<HakoCpp_MultiArrayDimension> dim;
        Hako_uint32 data_offset;
} HakoCpp_MultiArrayLayout;

#endif /* _pdu_cpptype_std_msgs_MultiArrayLayout_HPP_ */
