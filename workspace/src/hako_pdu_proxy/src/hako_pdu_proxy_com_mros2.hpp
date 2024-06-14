#ifndef _CAN_PROXY_COM_MROS2_HPP_
#define _CAN_PROXY_COM_MROS2_HPP_

#include <mros2.h>

extern void hako_pdu_proxy_com_pub_init(mros2::Node *node);
extern void hako_pdu_proxy_com_sub_init(mros2::Node *node);

#define DECLARE_PUBLISHER(type, topic_name) \
    static mros2::Publisher publisher_ ##topic_name

#define PUBLISH_TOPIC(topic_name, msg)   \
do {    \
        PUBLISHER(topic_name).publish(msg);    \
} while (0)

#define DECLARE_SUBSCRIBER(type, topic_name) \
    static mros2::Subscriber subscriber_ ##topic_name

#define DEFINE_SUB_CALLBACK(pkg, ros_type, robo_name, channel_id, topic_name) \
static void SUB_CALLBACK_NAME(topic_name)(pkg::msg::ros_type *ros_msg) \
{   \
    Hako_ ##ros_type *pdu_msg;   \
    int total_size = hako_convert_ros2pdu_ ##ros_type (*ros_msg, &pdu_msg); \
    hako_pdu_proxy_tx_data(robo_name, (channel_id), (char*)pdu_msg, total_size);    \
    hako_destroy_pdu(pdu_msg); \
}

#define ROS_NODE_TYPE mros2::Node*

#include "cmsis_os.h"
#include "netif.h"
#include "netif_posix_add.h"

static inline ROS_NODE_TYPE hako_pdu_proxy_ros_init(int argc, char** argv, const char* node_name)
{
    netif_posix_add(NETIF_IPADDR, NETIF_NETMASK);

    osKernelStart();

    printf("mros2-posix start!\r\n");
    printf("app name: hako_pdu_proxy(mros2-posix)\r\n");
    mros2::init(0, NULL);
    MROS2_DEBUG("mROS 2 initialization is completed\r\n");

    static mros2::Node node_ = mros2::Node::create_node(node_name);
    return &node_;
}

#define HAKO_PDU_PROXY_ROS_WALL_RATE(var, rate) 
#define HAKO_PDU_PROXY_ROS_WALL_RATE_sleep(rate) 

static inline bool hako_pdu_proxy_ros_ok()
{
    return true;
}

static inline void hako_pdu_proxy_ros_shutdown()
{
    //nothing to do
}

static inline void hako_pdu_proxy_ros_spin(ROS_NODE_TYPE node)
{
    //mros2::spin();
    usleep(10*1000); //sleep 10msec
}

#endif /* _CAN_PROXY_COM_MROS2_HPP_ */