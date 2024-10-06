#ifndef _pdu_cpptype_hako_msgs_Disturbance_HPP_
#define _pdu_cpptype_hako_msgs_Disturbance_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "geometry_msgs/pdu_cpptype_Vector3.hpp"
#include "hako_msgs/pdu_cpptype_DisturbanceTemperature.hpp"
#include "hako_msgs/pdu_cpptype_DisturbanceWind.hpp"

typedef struct {
        HakoCpp_DisturbanceTemperature d_temp;
        HakoCpp_DisturbanceWind d_wind;
} HakoCpp_Disturbance;

#endif /* _pdu_cpptype_hako_msgs_Disturbance_HPP_ */
