#!/bin/bash

function create_dependent_pdus()
{
	COUNT=`wc -l dep_types.txt | awk '{print $1}'`
	if [ ${COUNT} -eq 0 ]
	then
		return
	fi
	for dep_msg in `cat dep_types.txt`
	do
		bash create_pdu_ctypes.bash ./config/search_path.txt ${dep_msg}
		bash create_pdu_ctypes_offset.bash ./config/search_path.txt ${dep_msg}
	done
}

for msg in `cat ./config/ros_msgs.txt`
do
	bash create_pdu_ctypes.bash ./config/search_path.txt ${msg}
	bash create_pdu_ctypes_offset.bash ./config/search_path.txt ${msg}
	create_dependent_pdus
done
