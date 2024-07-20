#ifndef _pdu_cpptype_hako_msgs_ManualPosAttControl_HPP_
#define _pdu_cpptype_hako_msgs_ManualPosAttControl_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        Hako_bool do_operation;
        HakoCpp_Twist posatt;
} HakoCpp_ManualPosAttControl;

#endif /* _pdu_cpptype_hako_msgs_ManualPosAttControl_HPP_ */
