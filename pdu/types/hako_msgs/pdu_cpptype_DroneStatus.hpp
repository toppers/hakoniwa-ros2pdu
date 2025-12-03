#ifndef _pdu_cpptype_hako_msgs_DroneStatus_HPP_
#define _pdu_cpptype_hako_msgs_DroneStatus_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"

typedef struct {
        Hako_int32 flight_mode;
        Hako_int32 internal_state;
        HakoCpp_Vector3 propeller_wind;
        Hako_int32 collided_counts;
} HakoCpp_DroneStatus;

#endif /* _pdu_cpptype_hako_msgs_DroneStatus_HPP_ */
