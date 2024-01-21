# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(SystemMonitor)

find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

MESSAGE(${PROTOBUF_PROTOC_EXECUTABLE})
MESSAGE(${PROTOBUF_LIBRARY})
MESSAGE(${PROTOBUF_INCLUDE_DIR})

get_filename_component(PROTO_PATH ${CMAKE_SOURCE_DIR} DIRECTORY)
set(PROTO_PATH ${PROTO_PATH}/proto)

MESSAGE(${PROTO_PATH})

# Generate ProtoBuf files
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
set(GENERATED_PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)

execute_process(COMMAND  which grpc_cpp_plugin OUTPUT_VARIABLE GRPC_CPP_PLUGIN)
string(STRIP ${GRPC_CPP_PLUGIN} GRPC_CPP_PLUGIN)

message("file name " ${PROTO_FILE_NAME})
message("file path " ${PROTO_PATH})
message("GRPC_CPP_PLUGIN " ${GENERATED_PROTOBUF_PATH})

add_custom_command(
    OUTPUT   "system_monitor.pb.h"
            "system_monitor.pb.cc"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "--proto_path=${PROTO_PATH}"
    "--grpc_out=${GENERATED_PROTOBUF_PATH}"
    "--plugin=protoc-gen-grpc=`which grpc_cpp_plugin`"
    "${PROTO_PATH}/system_monitor.proto"
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

set(GENERATED_PROTOBUF_FILES
    ${GENERATED_PROTO_DIR}/system_monitor.pb.cc
    ${GENERATED_PROTO_DIR}/system_monitor.pb.h
    ${GENERATED_PROTO_DIR}/system_monitor.grpc.pb.cc
    ${GENERATED_PROTO_DIR}/system_monitor.grpc.pb.h
)

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
                        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h
                        PRIVATE ${PROTOBUF_INCLUDE_DIR})

# Set link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC pthread
                                        ${PROTOBUF_LIBRARY}
                                        protobuf::libprotobuf gRPC::grpc gRPC::grpc++)
