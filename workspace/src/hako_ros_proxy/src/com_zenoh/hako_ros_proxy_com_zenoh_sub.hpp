#ifndef _HAKO_ROS_PROXY_ZENOH_SUB_HPP_
#define _HAKO_ROS_PROXY_ZENOH_SUB_HPP_

#include "hako_ros_proxy_com_zenoh.hpp"
#ifdef MROS2
#include "hako_ros_proxy_com_mros2_pub.hpp"
#else
#include "../com_ros2/ros2/hako_ros_proxy_com_ros2_pub.hpp"
#endif

#define ZENOH_SUBSCRIBER(topic_name) zenoh_subscriber_ ##topic_name
#define ZENOH_DECLARE_SUBSCRIBER(topic_name) \
    static z_owned_subscriber_t ZENOH_SUBSCRIBER(topic_name)

#define ZENOH_SUB_CALLBACK_NAME(topic_name)   zenoh_callback_ ##topic_name
#define ZENOH_DEFINE_SUB_CALLBACK(pkg, ros_type, topic_name) \
static void ZENOH_SUB_CALLBACK_NAME(topic_name)(const z_sample_t *sample, void *) \
{   \
    void *top_ptr = (void *)sample->payload.start;   \
    Hako_ ##ros_type *pdu_msg = (Hako_ ##ros_type *)hako_get_base_ptr_pdu(top_ptr); \
    if (pdu_msg != nullptr) { \
        auto ros_msg = pkg::msg::ros_type();  \
        hako_convert_pdu2ros_ ##ros_type (*pdu_msg,  ros_msg); \
        ROS_PROXY_PUBLISH_TOPIC(topic_name, ros_msg); \
    } \
}

#define ZENOH_CREATE_SUBSCRIBER(topic_name) \
do {    \
    z_owned_closure_sample_t callback = z_closure(ZENOH_SUB_CALLBACK_NAME(topic_name), NULL); \
    ZENOH_SUBSCRIBER(topic_name) = z_declare_subscriber(z_loan(hako_ros_proxy_zenoh_session.s), z_keyexpr( #topic_name ), z_move(callback), NULL);    \
    std::cout << "INFO: HakoRosProxy zenoh subscriber: " << #topic_name << std::endl; \
} while (0)

#endif /* _HAKO_ROS_PROXY_ZENOH_HPP_ */
