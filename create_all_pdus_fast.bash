#!/bin/bash

declare -A GENERATED

function process_pdu()
{
    local msg=$1
    if [ -n "${GENERATED[$msg]}" ]; then
        echo "INFO: Skip already processed: ${msg}"
        return
    fi
    bash create_pdu_ctypes.bash ./config/search_path.txt ${msg}
    bash create_pdu_ctypes_offset.bash ./config/search_path.txt ${msg}
    GENERATED[$msg]=1
}

function create_dependent_pdus()
{
    COUNT=`wc -l dep_types.txt | awk '{print $1}'`
    if [ ${COUNT} -eq 0 ]; then
        return
    fi
    for dep_msg in `cat dep_types.txt`
    do
        process_pdu ${dep_msg}
    done
}

for msg in `cat ./config/ros_msgs.txt`
do
    process_pdu ${msg}
    create_dependent_pdus
done
