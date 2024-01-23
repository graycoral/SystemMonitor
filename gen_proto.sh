
#!/bin/bash

# Generate protobuf code
protoc --proto_path=./proto --cpp_out=./proto ./proto/system_monitor.proto

# Generate gRPC stubs
protoc --proto_path=./proto --grpc_out=./proto --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./proto/system_monitor.proto