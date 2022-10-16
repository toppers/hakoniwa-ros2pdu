#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Usage: $0 <search_path> <ros_msg_pkg/ros_msg_type>"
    exit 1
fi

CURR_DIR=`pwd`
TOOL_DIR=utils
JSON_DIR=${TOOL_DIR}/ros_json
TYPES_DIR=${TOOL_DIR}/ros_types
OUT_DIR=pdu/offset
OUT_JSON_DIR=pdu/json

SEARCH_PATH=${CURR_DIR}/${1}
PKG_MSG=${2}

PKG_NAME=`echo ${PKG_MSG} | awk -F/ '{print $1}'`
MSG_NAME=`echo ${PKG_MSG} | awk -F/ '{print $2}'`

#find dependent types
cd ${TYPES_DIR}
bash find_deptypes.bash ${SEARCH_PATH} ${PKG_MSG} > ${CURR_DIR}/dep_types.txt
cd ${CURR_DIR}

python3 utils/template_engine/generate.py ./template/pdu_ctypes_offset_c.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp.c
gcc -o tmp -I./pdu/types tmp.c 

if [ -d ${OUT_DIR}/${PKG_NAME} ]
then
    :
else
    mkdir -p ${OUT_DIR}/${PKG_NAME}
fi
./tmp > ${OUT_DIR}/${PKG_NAME}/${MSG_NAME}.offset
rm -f tmp.c tmp
