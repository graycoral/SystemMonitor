# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(SystemMonitor)

find_package(Threads REQUIRED)
# find_package(Protobuf REQUIRED)
# include_directories(${PROTOBUF_INCLUDE_DIR})

# Generate ProtoBuf files
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
set(GENERATED_PROTO_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto)

add_custom_command(
      OUTPUT "${GENERATED_PROTO_DIR}/system_monitor.pb.cc" "${GENERATED_PROTO_DIR}/system_monitor.pb.h"
      COMMAND /usr/bin/protoc
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${PROTO_SRC_DIR}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${rg_proto}"
      DEPENDS "${rg_proto}"
)


# Add source files
set(SOURCES
    src/main.cpp
    src/system_monitor.cpp
    src/sender/system_monitor_sender.cpp
    src/sender/system_monitor_sender_grafana.cpp
    src/reader/system_monitor_reader.cpp
    src/reader/system_monitor_data_reader_linux.cpp
)

include_directories(${GENERATED_PROTO_DIR})

# For MAC M1 or M2 process
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Add header files
set(HEADERS
    h/
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${GENERATED_PROTOBUF_FILES})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include
                        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h)

# Set link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
