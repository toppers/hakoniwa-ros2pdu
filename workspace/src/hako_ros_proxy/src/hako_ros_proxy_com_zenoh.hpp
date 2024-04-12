#ifndef _HAKO_ROS_PROXY_ZENOH_HPP_
#define _HAKO_ROS_PROXY_ZENOH_HPP_

#include "zenoh.h"

typedef struct {
    z_owned_session_t s;
} HakoZenohSessionType;
extern HakoZenohSessionType hako_ros_proxy_zenoh_session;
extern bool hako_ros_proxy_zenoh_initialize();
extern void hako_ros_proxy_zenoh_finalize();

#endif /* _HAKO_ROS_PROXY_ZENOH_HPP_ */
