#!/bin/bash

IMAGE_NAME=`cat docker/image_name.txt`
IMAGE_TAG=`cat appendix/latest_version.txt`
DOCKER_IMAGE=${IMAGE_NAME}:${IMAGE_TAG}
DOCKER_FILE=docker/Dockerfile

ARCH=`arch`
OS_TYPE=`bash utils/detect_os_type.bash`

if [ ${OS_TYPE} != "Mac" ]
then
	docker build -t ${DOCKER_IMAGE} -f ${DOCKER_FILE} .
else
	if [ $ARCH = "arm64" ]
	then
		docker build --platform linux/amd64 -t ${DOCKER_IMAGE} -f ${DOCKER_FILE} .

	else
		docker build -t ${DOCKER_IMAGE} -f ${DOCKER_FILE} .
	fi
fi


