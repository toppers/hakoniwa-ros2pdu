FROM ros:foxy as hakoniwa-ros2pdu-dev

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
	git	\
	build-essential	\
	gcc	\
	g++	\
	vim	\
	libssl-dev \
	make	\
	autoconf \
	automake \
	pkg-config \
	curl \
	libffi-dev \
	python3-dev \
	python3-pip \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*


RUN mkdir /root/workspace
WORKDIR /root/workspace

#hakoniwa-core
ENV PATH /root/workspace/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-master/:${PATH}
ENV PATH /root/workspace/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-cmd/:${PATH}
RUN git clone --recursive https://github.com/toppers/hakoniwa-core-cpp-client.git
WORKDIR /root/workspace/hakoniwa-core-cpp-client
RUN bash build.bash


# jinja2
RUN pip install jinja2

WORKDIR /root/workspace

RUN apt-get update && apt-get install -y jq
RUN pip3 --no-cache-dir install yq
