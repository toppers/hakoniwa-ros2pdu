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

# Rust
ENV RUST_HOME /usr/local/lib/rust
ENV RUSTUP_HOME ${RUST_HOME}/rustup
ENV CARGO_HOME ${RUST_HOME}/cargo
RUN mkdir /usr/local/lib/rust && \
    chmod 0755 $RUST_HOME
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs > ${RUST_HOME}/rustup.sh \
    && chmod +x ${RUST_HOME}/rustup.sh \
    && ${RUST_HOME}/rustup.sh -y --default-toolchain nightly --no-modify-path
ENV PATH $PATH:$CARGO_HOME/bin

# zenoh-c
RUN git clone https://github.com/eclipse-zenoh/zenoh-c.git
WORKDIR /root/workspace/zenoh-c
RUN mkdir -p ../zenoh-build
WORKDIR /root/workspace/zenoh-build
RUN cmake ../zenoh-c
RUN cmake --build . --config Release
RUN cmake --build . --target install


# hakoniwa-core
WORKDIR /root/workspace
RUN git clone --recursive https://github.com/toppers/hakoniwa-core-cpp-client.git
WORKDIR /root/workspace/hakoniwa-core-cpp-client
RUN bash build.bash
RUN bash install.bash
ENV PATH /root/workspace/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-master/:${PATH}
ENV PATH /root/workspace/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-cmd/:${PATH}


# jinja2
RUN pip install jinja2

WORKDIR /root/workspace

RUN apt-get update && apt-get install -y jq
RUN pip3 --no-cache-dir install yq


# MAVROS
RUN apt-get update && apt-get install -y \
    ros-foxy-mavros \
    ros-foxy-mavros-extras \
    geographiclib-tools \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*