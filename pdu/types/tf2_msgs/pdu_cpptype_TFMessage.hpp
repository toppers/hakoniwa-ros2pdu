#ifndef _pdu_cpptype_tf2_msgs_TFMessage_HPP_
#define _pdu_cpptype_tf2_msgs_TFMessage_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "geometry_msgs/pdu_cpptype_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_Transform.hpp"
#include "geometry_msgs/pdu_cpptype_TransformStamped.hpp"
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        std::vector<HakoCpp_TransformStamped> transforms;
} HakoCpp_TFMessage;

#endif /* _pdu_cpptype_tf2_msgs_TFMessage_HPP_ */
