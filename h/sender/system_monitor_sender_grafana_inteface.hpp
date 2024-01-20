#ifndef SYSTEM_MONITOR_SENDER_GRAFANA_INTERFACE_HPP
#define SYSTEM_MONITOR_SENDER_GRAFANA_INTERFACE_HPP

#include "system_monitor.pb.h"

class ISystemMonitorSenderGrafana
    : public systemmonitor::SystemMonitor::Service {
  virtual ~ISystemMonitorSenderGrafana() = default;

 public:
  virtual grpc::Status GetCpuUsage(
      grpc::ServerContext* context,
      const systemmonitor::CpuUsageRequest* request,
      systemmonitor::CpuUsageResponse* response) = 0;
  virtual grpc::Status GetMemoryUsage(
      grpc::ServerContext* context,
      const systemmonitor::MemoryUsageRequest* request,
      systemmonitor::MemoryUsageResponse* response) = 0;
};

#endif  // SYSTEM_MONITOR_SENDER_GRAFANA_INTERFACE_HPP