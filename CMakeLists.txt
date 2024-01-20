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
set(GENERATED_PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)

# Generate ProtoBuf files
# add_custom_command(
#     OUTPUT "${GENERATED_PROTO_DIR}/system_monitor.pb.cc" "${GENERATED_PROTO_DIR}/system_monitor.pb.h"
#     COMMAND protoc
#     ARGS --grpc_out "${GENERATED_PROTO_DIR}"
#         --cpp_out "${GENERATED_PROTO_DIR}"
#         -I "${PROTO_SRC_DIR}/system_monitor.proto"
#     DEPENDS "${PROTO_SRC_DIR}/system_monitor.proto"
# )
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

set(GENERATED_PROTOBUF_FILES
    ${GENERATED_PROTO_DIR}/system_monitor.pb.cc
    ${GENERATED_PROTO_DIR}/system_monitor.pb.h
)

# For MAC M1 or M2 process
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Add header files
set(HEADERS
    h/
    proto/
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${GENERATED_PROTOBUF_FILES})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include
                        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h
                        PRIVATE ${PROTOBUF_INCLUDE_DIR})

# Set link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC pthread ${PROTOBUF_LIBRARY})
