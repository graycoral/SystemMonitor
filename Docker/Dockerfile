# Ubuntu 베이스 이미지 사용
FROM ubuntu:latest

# 필요한 패키지 설치
RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    autoconf \
    libtool \
    pkg-config \
    clang \
    libc++-dev \
    python3 \
    python3-pip \
    python3-dev \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

# Python gRPC 패키지 설치
RUN pip3 install grpcio grpcio-tools

# C++ gRPC 설치
RUN git clone https://github.com/grpc/grpc \
    && cd grpc \
    && git submodule update --init \
    && mkdir -p cmake/build \
    && cd cmake/build \
    && cmake -DgRPC_INSTALL=ON \
        -DgRPC_BUILD_TESTS=OFF \
        ../.. \
    && make -j3\
    && make install
