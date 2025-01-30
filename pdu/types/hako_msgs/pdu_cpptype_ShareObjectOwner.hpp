#ifndef _pdu_cpptype_hako_msgs_ShareObjectOwner_HPP_
#define _pdu_cpptype_hako_msgs_ShareObjectOwner_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        std::string object_name;
        Hako_uint32 owner_id;
        Hako_uint64 last_update;
        HakoCpp_Twist pos;
} HakoCpp_ShareObjectOwner;

#endif /* _pdu_cpptype_hako_msgs_ShareObjectOwner_HPP_ */
