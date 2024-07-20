#ifndef _pdu_cpptype_hako_msgs_HakoCmdMagnetHolder_HPP_
#define _pdu_cpptype_hako_msgs_HakoCmdMagnetHolder_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
#include "hako_msgs/pdu_cpptype_HakoCmdHeader.hpp"

typedef struct {
        HakoCpp_HakoCmdHeader header;
        Hako_bool magnet_on;
} HakoCpp_HakoCmdMagnetHolder;

#endif /* _pdu_cpptype_hako_msgs_HakoCmdMagnetHolder_HPP_ */
