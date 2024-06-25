#!/bin/bash

UNITY_SIMASSET_DIR=../hakoniwa-unity-simasset-plugin
if [ ! -d ${UNITY_SIMASSET_DIR} ]
then
    echo "ERROR: can not find on ${UNITY_SIMASSET_DIR}"
fi
CORE_CPP_CLIENT_DIR=../hakoniwa-core-cpp-client
if [ ! -d ${CORE_CPP_CLIENT_DIR} ]
then
    echo "ERROR: can not find on ${CORE_CPP_CLIENT_DIR}"
fi

# hakoniwa-unity-simasset-plugin
cp -rp pdu/offset ${UNITY_SIMASSET_DIR}/plugin-srcs/ros_types/
cp -rp pdu/json ${UNITY_SIMASSET_DIR}/plugin-srcs/ros_types

# hakoniwa-core-cpp-client
 cp -rp pdu/offset ${CORE_CPP_CLIENT_DIR}/bindings/python/hako_binary/
 