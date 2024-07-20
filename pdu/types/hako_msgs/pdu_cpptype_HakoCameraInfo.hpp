#ifndef _pdu_cpptype_hako_msgs_HakoCameraInfo_HPP_
#define _pdu_cpptype_hako_msgs_HakoCameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        Hako_int32 request_id;
        HakoCpp_Vector3 angle;
} HakoCpp_HakoCameraInfo;

#endif /* _pdu_cpptype_hako_msgs_HakoCameraInfo_HPP_ */
