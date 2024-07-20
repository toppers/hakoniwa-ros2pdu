#ifndef _pdu_cpptype_hako_msgs_HakoCmdCameraMove_HPP_
#define _pdu_cpptype_hako_msgs_HakoCmdCameraMove_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "hako_msgs/pdu_cpptype_HakoCmdHeader.hpp"

typedef struct {
        HakoCpp_HakoCmdHeader header;
        Hako_int32 request_id;
        HakoCpp_Vector3 angle;
} HakoCpp_HakoCmdCameraMove;

#endif /* _pdu_cpptype_hako_msgs_HakoCmdCameraMove_HPP_ */
