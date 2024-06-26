#ifndef _HAKO_ROS_PROXY_ZENOH_PUB_HPP_
#define _HAKO_ROS_PROXY_ZENOH_PUB_HPP_

#include "hako_ros_proxy_com_zenoh.hpp"

#define ZENOH_PUBLISHER(topic_name) zenoh_publisher_ ##topic_name
#define ZENOH_DECLARE_PUBLISHER(topic_name) \
    static z_owned_publisher_t ZENOH_PUBLISHER(topic_name)

#define ZENOH_CREATE_PUBLISHER(topic_name) \
do {    \
    ZENOH_PUBLISHER(topic_name) = z_declare_publisher(z_loan(hako_ros_proxy_zenoh_session.s), z_keyexpr( #topic_name ), NULL);    \
    if (!z_check(ZENOH_PUBLISHER(topic_name))) {  \
        std::cerr << "Unable to declare zenoh Publisher for key expression!" << std::endl;    \
    }   \
    std::cout << "INFO: HakoRosProxy zenoh publisher: " << #topic_name << std::endl; \
} while (0)

#define ZENOH_PUBLISH_TOPIC(topic_name, binary_data, size) \
do {    \
    z_publisher_put_options_t options = z_publisher_put_options_default();  \
    int ret = z_publisher_put(z_loan(ZENOH_PUBLISHER(topic_name)), (const uint8_t *)binary_data, size, &options);    \
    if (ret != 0) { \
        std::cerr << "ERROR: can not zenoh publish: topic_name = " << #topic_name " pdu_size = " << size << std::endl;   \
    }   \
} while (0)




#endif /* _HAKO_ROS_PROXY_ZENOH_PUB_HPP_ */