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
OUT_DIR=pdu/types
CSHARP_OUT_DIR=pdu/csharp
OUT_JSON_DIR=pdu/json

SEARCH_PATH=${CURR_DIR}/${1}
PKG_MSG=${2}

PKG_NAME=`echo ${PKG_MSG} | awk -F/ '{print $1}'`
MSG_NAME=`echo ${PKG_MSG} | awk -F/ '{print $2}'`

#find dependent types
cd ${TYPES_DIR}
bash find_deptypes.bash ${SEARCH_PATH} ${PKG_MSG} > ${CURR_DIR}/dep_types.txt
cd ${CURR_DIR}

#create json file
cd ${JSON_DIR}
bash convert_rosmsg2json.bash ${SEARCH_PATH} ${PKG_MSG} ${CURR_DIR}/${OUT_JSON_DIR}
cd ${CURR_DIR}

#convert json file to c type header
python3 utils/template_engine/generate.py ./template/pdu_ctypes_h.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_header.txt
python3 utils/template_engine/generate.py ./template/pdu_csharp_class.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_csharp.txt
python3 utils/template_engine/generate.py ./template/pdu_ctypes_conv_cpp.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_cpp.txt
python3 utils/template_engine/generate.py ./template/pdu_cpptypes_hpp.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_cpp_header.txt
python3 utils/template_engine/generate.py ./template/pdu_cpptypes_conv_cpp.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_cpp_cpp.txt

# for mavlink only
#python3 utils/template_engine/generate.py ./template/pdu_ctypes_conv_mavlink_cpp.tpl ./${OUT_JSON_DIR}/${PKG_MSG}.json  ${CURR_DIR}/dep_types.txt ./config/varray_size.json > tmp_mavlink_cpp.txt

if [ -d ${OUT_DIR}/${PKG_NAME} ]
then
    :
else
    mkdir -p ${OUT_DIR}/${PKG_NAME}
fi

if [ ! -e ${CSHARP_OUT_DIR}/${PKG_NAME} ]
then
    mkdir -p ${CSHARP_OUT_DIR}/${PKG_NAME}
fi

mv tmp_header.txt ${OUT_DIR}/${PKG_NAME}/pdu_ctype_${MSG_NAME}.h 
mv tmp_csharp.txt ${CSHARP_OUT_DIR}/${PKG_NAME}/${MSG_NAME}.cs
mv tmp_cpp_header.txt ${OUT_DIR}/${PKG_NAME}/pdu_cpptype_${MSG_NAME}.hpp 
mv tmp_cpp.txt ${OUT_DIR}/${PKG_NAME}/pdu_ctype_conv_${MSG_NAME}.hpp
mv tmp_cpp_cpp.txt ${OUT_DIR}/${PKG_NAME}/pdu_cpptype_conv_${MSG_NAME}.hpp

# for mavlink only 
#mv tmp_mavlink_cpp.txt ${OUT_DIR}/${PKG_NAME}/pdu_ctype_conv_mavlink_${MSG_NAME}.hpp


