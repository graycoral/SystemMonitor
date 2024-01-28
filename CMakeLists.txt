# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(SystemMonitor)

find_package(Protobuf REQUIRED)
find_package(absl CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

MESSAGE(${PROTOBUF_PROTOC_EXECUTABLE})
MESSAGE(${PROTOBUF_LIBRARY})
MESSAGE(${PROTOBUF_INCLUDE_DIR})

# Set output directory
set(PROTO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/proto)

MESSAGE(${PROTO_PATH})
# Generate ProtoBuf files
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
set(PROTO_FILE_NAME system_monitor)
set(GENERATED_PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
set(PROTOBUF_PROTOC_EXECUTABLE protoc)

execute_process(COMMAND which grpc_cpp_plugin OUTPUT_VARIABLE GRPC_CPP_PLUGIN)
string(STRIP ${GRPC_CPP_PLUGIN} GRPC_CPP_PLUGIN)

message("file path " ${PROTO_PATH})
message("GENERATED_PROTOBUF_PATH " ${GENERATED_PROTOBUF_PATH})
message("PROTOBUF_LIBRARY " ${PROTOBUF_LIBRARY})

add_custom_command(
    OUTPUT   " ${GENERATED_PROTO_DIR}/${PROTO_FILE_NAME}.pb.h" "${GENERATED_PROTO_DIR}/${PROTO_FILE_NAME}.pb.cc"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS --cpp_out="${PROTO_PATH}"
    -I="${PROTO_PATH}" "${PROTO_PATH}/${PROTO_FILE_NAME}.proto"
    DEPENDS "${PROTO_PATH}/${PROTO_FILE_NAME}.proto"
)

add_custom_command(
    OUTPUT   "${PROTO_PATH}/${PROTO_FILE_NAME}.grpc.pb.h" "${PROTO_PATH}/${PROTO_FILE_NAME}.grpc.pb.cc"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS --grpc_out="${PROTO_PATH}"
    -I="${PROTO_PATH}"
    --plugin=protoc-gen-grpc="${GRPC_CPP_PLUGIN}" "${PROTO_PATH}/${PROTO_FILE_NAME}.proto"
    DEPENDS "${PROTO_PATH}/${PROTO_FILE_NAME}.proto"
)

set(PROTO_FILE
    proto/system_monitor.proto
)

# Add source files
set(SOURCES
    src/main.cpp
    src/system_monitor.cpp
    src/sender/system_monitor_sender.cpp
    src/sender/system_monitor_sender_grafana.cpp
    src/reader/system_monitor_reader.cpp
    src/reader/system_monitor_data_reader_linux.cpp
    ${GENERATED_PROTO_DIR}/${PROTO_FILE_NAME}.pb.cc
    ${GENERATED_PROTO_DIR}/${PROTO_FILE_NAME}.grpc.pb.cc
)

include_directories(${GENERATED_PROTO_DIR})

# For MAC M1 or M2 process
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Add header files
set(HEADERS
    h/
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include
                                            PUBLIC
                                            ${HEADERS}
                                            ${GENERATED_PROTO_DIR})

# Set link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC pthread
                                        # ${PROTOBUF_LIBRARY}  PRIVATE /usr/local/lib/libprotobuf.dylib
                                        protobuf::libprotobuf
                                        gRPC::grpc
                                        gRPC::grpc++
                                    )