#ifndef _pdu_cpptype_hako_msgs_HakoDroneCmdHeader_HPP_
#define _pdu_cpptype_hako_msgs_HakoDroneCmdHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_bool request;
        Hako_bool result;
        Hako_int32 result_code;
} HakoCpp_HakoDroneCmdHeader;

#endif /* _pdu_cpptype_hako_msgs_HakoDroneCmdHeader_HPP_ */
