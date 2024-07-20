#ifndef _pdu_cpptype_std_msgs_Int8MultiArray_HPP_
#define _pdu_cpptype_std_msgs_Int8MultiArray_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "std_msgs/pdu_cpptype_MultiArrayDimension.hpp"
#include "std_msgs/pdu_cpptype_MultiArrayLayout.hpp"

typedef struct {
        HakoCpp_MultiArrayLayout layout;
        std::vector<Hako_int8> data;
} HakoCpp_Int8MultiArray;

#endif /* _pdu_cpptype_std_msgs_Int8MultiArray_HPP_ */
