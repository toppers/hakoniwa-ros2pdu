#ifndef _CAN_PROXY_HAKO_HPP_
#define _CAN_PROXY_HAKO_HPP_

#include <string>
#include <hako.hpp>

extern bool can_proxy_hako_init(const char *asset_name, HakoTimeType delta_usec);
extern bool can_proxy_hako_run();
extern void can_proxy_hako_fin();

#endif /* _CAN_PROXY_HAKO_HPP_ */