#ifndef _pdu_cpptype_pico_msgs_LightSensor_HPP_
#define _pdu_cpptype_pico_msgs_LightSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>

typedef struct {
        Hako_int16 forward_r;
        Hako_int16 forward_l;
        Hako_int16 left;
        Hako_int16 right;
} HakoCpp_LightSensor;

#endif /* _pdu_cpptype_pico_msgs_LightSensor_HPP_ */
