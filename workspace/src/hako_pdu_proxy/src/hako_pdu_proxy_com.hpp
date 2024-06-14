#ifndef _CAN_PROXY_COM_HPP_
#define _CAN_PROXY_COM_HPP_

#define PUBLISHER_NUM   1
typedef struct {
    int pdu_channel;
    const char* topic_name;
} HakoTopicPduMapType;


extern void hako_pdu_proxy_com_publish(void);


/*
 * internal apis
 */

#define PUBLISHER(topic_name) publisher_ ##topic_name
#define CREATE_PUBLISHER(pkg, ros_type, robo_name, channel_id, topic_name) \
do {    \
    PUBLISHER(topic_name) = my_node->create_publisher<pkg::msg::ros_type>(#topic_name, 1);    \
} while (0)

#define PUBLISH_PDU_TOPIC(pkg, ros_type, robo_name, channel_id, topic_name, count, write_cycle) \
do {    \
    if (((count) % (write_cycle)) == 0) {   \
        HakoPduMetaDataType meta; \
        if (hako_pdu_proxy_rx_data(robo_name, (channel_id), (char*)&meta, sizeof(meta))) {    \
            char* buffer = (char*)malloc(meta.total_size); \
            if ((buffer != NULL) && hako_pdu_proxy_rx_data(robo_name, (channel_id), buffer, meta.total_size)) {    \
                auto ros_msg = pkg::msg::ros_type();  \
                Hako_ ##ros_type *pdu_msg = (Hako_ ##ros_type *)hako_get_base_ptr_pdu((void*)buffer);   \
                if (pdu_msg != NULL) { \
                    hako_convert_pdu2ros_ ##ros_type (pdu_msg, ros_msg); \
                    PUBLISH_TOPIC(topic_name, ros_msg);   \
                } \
                free(buffer); \
            } else { \
                if (buffer != NULL) { \
                    free(buffer); \
                } \
            } \
        } \
    }   \
} while (0)

#define SUBSCRIBER(topic_name) subscriber_ ##topic_name
#define SUB_CALLBACK_NAME(topic_name)   callback_ ##topic_name
#define CREATE_SUBSCRIBER(pkg, ros_type, robo_name, channel_id, topic_name) \
do {    \
    hako_pdu_proxy_tx_init(robo_name, (channel_id), sizeof(Hako_ ##ros_type)); \
    SUBSCRIBER(topic_name) = my_node->create_subscription<pkg::msg::ros_type>(#topic_name, 1, SUB_CALLBACK_NAME(topic_name));    \
} while (0)


#ifdef MROS2
#include "hako_pdu_proxy_com_mros2.hpp"
#else
#include "hako_pdu_proxy_com_ros2.hpp"
#endif

#endif /* _CAN_PROXY_COM_HPP_ */
