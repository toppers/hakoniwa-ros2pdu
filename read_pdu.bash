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

if [ $# -eq 3 ]
then
    python3 ./utils/binary/binary_reader.py ./pdu/offset ${TYPE} ${BINFILE}  | jq
else
    python3 ./utils/binary/binary_reader.py ./pdu/offset ${TYPE} ${BINFILE}  | yq -y
fi

