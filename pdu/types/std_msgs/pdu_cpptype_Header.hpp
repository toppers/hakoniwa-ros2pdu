#ifndef _pdu_cpptype_std_msgs_Header_HPP_
#define _pdu_cpptype_std_msgs_Header_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"

typedef struct {
        HakoCpp_Time stamp;
        std::string frame_id;
} HakoCpp_Header;

#endif /* _pdu_cpptype_std_msgs_Header_HPP_ */
