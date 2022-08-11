#ifndef _CAN_PROXY_COM_HPP_
#define _CAN_PROXY_COM_HPP_

#define HAKO_PDU_CHANNEL_MAX    1024
#define PUBLISHER_NUM   1
typedef struct {
    int pdu_channel;
    const char* topic_name;
} HakoTopicPduMapType;


#endif /* _CAN_PROXY_COM_HPP_ */