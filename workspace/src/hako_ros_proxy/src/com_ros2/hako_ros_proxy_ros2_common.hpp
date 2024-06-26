#ifndef _HAKO_ROS_PROXY_ROS2_COMMON_HPP_
#define _HAKO_ROS_PROXY_ROS2_COMMON_HPP_

/*
 * internal apis
 */
#define ROS_PROXY_PUBLISHER(topic_name) publisher_ ##topic_name
#define ROS_PROXY_CREATE_PUBLISHER(my_node, pkg, ros_type, topic_name) \
do {    \
    ROS_PROXY_PUBLISHER(topic_name) = my_node->create_publisher<pkg::msg::ros_type>(#topic_name, 1);    \
    std::cout << "INFO: HakoRosProxy ros publisher: " << #topic_name << std::endl; \
} while (0)


#define ROS_PROXY_PUBLISH_PDU_TOPIC(pkg, ros_type, topic_name) \
do {    \
    auto ros_msg = pkg::msg::ros_type();  \
    ROS_PROXY_PUBLISH_TOPIC(topic_name, ros_msg);   \
} while (0)

#define ROS_PROXY_SUBSCRIBER(topic_name) subscriber_ ##topic_name
#define ROS_PROXY_SUB_CALLBACK_NAME(topic_name)   callback_ ##topic_name
#define ROS_PROXY_CREATE_SUBSCRIBER(my_node, pkg, ros_type, topic_name) \
do {    \
    ROS_PROXY_SUBSCRIBER(topic_name) = my_node->create_subscription<pkg::msg::ros_type>(#topic_name, 1, ROS_PROXY_SUB_CALLBACK_NAME(topic_name));    \
    std::cout << "INFO: HakoRosProxy ros subscriber: " << #topic_name << std::endl; \
} while (0)



#endif /* _HAKO_ROS_PROXY_ROS2_COMMON_HPP_ */
