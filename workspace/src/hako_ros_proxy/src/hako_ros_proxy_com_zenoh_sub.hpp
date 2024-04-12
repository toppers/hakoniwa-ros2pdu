#ifndef _HAKO_ROS_PROXY_ZENOH_SUB_HPP_
#define _HAKO_ROS_PROXY_ZENOH_SUB_HPP_

#include "hako_ros_proxy_com_zenoh.hpp"

#define ZENOH_SUBSCRIBER(topic_name) zenoh_subscriber_ ##topic_name
#define ZENOH_DECLARE_SUBSCRIBER(topic_name) \
    static z_owned_subscriber_t ZENOH_SUBSCRIBER(topic_name)

#define ZENOH_SUB_CALLBACK_NAME(topic_name)   zenoh_callback_ ##topic_name
#define ZENOH_DEFINE_SUB_CALLBACK(pkg, ros_type, topic_name) \
static void ZENOH_SUB_CALLBACK_NAME(topic_name)(const z_sample_t *sample, void *) \
{   \
    Hako_ ##ros_type pdu_msg;   \
}

#define ZENOH_CREATE_SUBSCRIBER(topic_name) \
do {    \
    z_owned_closure_sample_t callback = z_closure(ZENOH_SUB_CALLBACK_NAME(topic_name), NULL); \
    ZENOH_SUBSCRIBER(topic_name) = z_declare_subscriber(z_loan(hako_ros_proxy_zenoh_session.s), z_keyexpr( #topic_name ), z_move(callback), NULL);    \
} while (0)

#endif /* _HAKO_ROS_PROXY_ZENOH_HPP_ */