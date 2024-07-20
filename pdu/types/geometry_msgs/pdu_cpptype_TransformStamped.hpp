#ifndef _pdu_cpptype_geometry_msgs_TransformStamped_HPP_
#define _pdu_cpptype_geometry_msgs_TransformStamped_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Transform.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        std::string child_frame_id;
        HakoCpp_Transform transform;
} HakoCpp_TransformStamped;

#endif /* _pdu_cpptype_geometry_msgs_TransformStamped_HPP_ */
