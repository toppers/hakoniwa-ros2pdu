#ifndef _pdu_cpptype_sensor_msgs_JointState_HPP_
#define _pdu_cpptype_sensor_msgs_JointState_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "builtin_interfaces/pdu_cpptype_Time.hpp"
#include "std_msgs/pdu_cpptype_Header.hpp"

typedef struct {
        HakoCpp_Header header;
        std::vector<std::string> name;
        std::vector<Hako_float64> position;
        std::vector<Hako_float64> velocity;
        std::vector<Hako_float64> effort;
} HakoCpp_JointState;

#endif /* _pdu_cpptype_sensor_msgs_JointState_HPP_ */
