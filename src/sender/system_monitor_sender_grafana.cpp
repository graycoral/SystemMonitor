#include "sender/system_monitor_sender_grafana.hpp"

SystemMonitorSenderGrafana::SystemMonitorSenderGrafana()
    : server_address_("0.0.0.0:50051") {}

bool SystemMonitorSenderGrafana::init() {
  // Prepare server builder
  grpc::ServerBuilder builder;

  // Listen on the given address without any authentication mechanism
  builder.AddListeningPort(server_address_, grpc::InsecureServerCredentials());

  // Register "this" instance to serve as the service
  builder.RegisterService(this);

  // Finally assemble the server
  server_ = builder.BuildAndStart();

  // Check if server is running
  if (server_ == nullptr) {
    return false;
  }

  return true;
}

bool SystemMonitorSenderGrafana::start() {
  // Check if server is initialized
  if (server_ == nullptr) {
    return false;
  }

  // Start the server and wait for it to shutdown
  // Note: This is a blocking call
  server_->Wait();

  return true;
}

bool SystemMonitorSenderGrafana::stop() {
  // Check if server is initialized
  if (server_ == nullptr) {
    return false;
  }

  // Shutdown the server
  server_->Shutdown();

  return true;
}

grpc::Status SystemMonitorSenderGrafana::GetCpuUsage(
    grpc::ServerContext* context, const systemmonitor::CpuUsageRequest* request,
    systemmonitor::CpuUsageResponse* response) {
  // Logic to get CPU usage and populate the response
  return grpc::Status::OK;
}

// grpc::Status SystemMonitorSenderGrafana::GetMemoryUsage(
//     grpc::ServerContext* context,
//     const systemmonitor::MemoryUsageRequest* request,
//     systemmonitor::MemoryUsageResponse* response) {
//   // Logic to get memory usage and populate the response
//   return grpc::Status::OK;
// }