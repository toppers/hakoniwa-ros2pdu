#ifndef _pdu_cpptype_can_msgs_HakoCan_HPP_
#define _pdu_cpptype_can_msgs_HakoCan_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "can_msgs/pdu_cpptype_HakoCanBody.hpp"
#include "can_msgs/pdu_cpptype_HakoCanHead.hpp"

typedef struct {
        HakoCpp_HakoCanHead head;
        HakoCpp_HakoCanBody body;
} HakoCpp_HakoCan;

#endif /* _pdu_cpptype_can_msgs_HakoCan_HPP_ */
