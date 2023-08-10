#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <custom.json>"
    exit 1
fi

CUSTOM_JSON=${1}
OUT_DIR=workspace/src/hako_pdu_proxy/src/gen

#convert json file to cpp codes
python3 utils/template_engine/generate_proxy.py \
    ./template/hako_pdu_proxy_com_pub_cpp.tpl \
    ${CUSTOM_JSON} > ${OUT_DIR}/hako_pdu_proxy_com_pub.cpp

python3 utils/template_engine/generate_proxy.py \
    ./template/hako_pdu_proxy_com_sub_cpp.tpl \
    ${CUSTOM_JSON} > ${OUT_DIR}/hako_pdu_proxy_com_sub.cpp

python3 utils/template_engine/generate_proxy.py \
    ./template/app_cpp.tpl \
    ${CUSTOM_JSON} > ${OUT_DIR}/app.cpp

