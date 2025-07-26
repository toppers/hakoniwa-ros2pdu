#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Usage: $0 <type> <json-file>"
    exit 1
fi

TYPE=${1}
JSONFILE=${2}

rm -f .tmp.bin
touch .tmp.bin

find  ./pdu/offset -name "${TYPE}.offset" | grep  "${TYPE}.offset" > /dev/null
if [ $? -ne 0 ]
then
    echo "ERROR: not found ${TYPE}"
    exit 1
fi

python3 -m utils.binary.binary_writer ./pdu/offset ${TYPE} ${JSONFILE}  out.bin
echo "Write to out.bin:"
od -x out.bin
