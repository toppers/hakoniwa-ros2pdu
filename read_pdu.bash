#!/bin/bash

if [ $# -ne 2 -a $# -ne 3 ]
then
    echo "Usage: $0 <type> <binfile> [json]"
    exit 1
fi

TYPE=${1}
BINFILE=${2}

find  ./pdu/offset -name "${TYPE}.offset" | grep  "${TYPE}.offset" > /dev/null
if [ $? -ne 0 ]
then
    echo "ERROR: not found ${TYPE}"
    exit 1
fi


python3 -m utils.binary.binary_reader ./pdu/offset ${TYPE} ${BINFILE}
