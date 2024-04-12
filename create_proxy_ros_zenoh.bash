#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <custom.json>"
    exit 1
fi

CUSTOM_JSON=${1}
OUT_DIR=workspace/src/hako_ros_proxy/src/gen

#convert json file to cpp codes
python3 utils/template_engine/generate_proxy.py \
    ./template/ros_zenoh/hako_pdu_proxy_com_zenoh_cpp.tpl \
    ${CUSTOM_JSON} > ${OUT_DIR}/hako_ros_proxy_com_zenoh.cpp

python3 utils/template_engine/generate_proxy.py \
    ./template/ros_zenoh/hako_pdu_proxy_com_ros2_cpp.tpl \
    ${CUSTOM_JSON} > ${OUT_DIR}/hako_ros_proxy_com_ros2.cpp


