#ifndef _pdu_cpptype_builtin_interfaces_Time_HPP_
#define _pdu_cpptype_builtin_interfaces_Time_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_int32 sec;
        Hako_uint32 nanosec;
} HakoCpp_Time;

#endif /* _pdu_cpptype_builtin_interfaces_Time_HPP_ */
