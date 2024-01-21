
#ifndef SYSTEM_MONITOR_SENDER_GRAFANA_HPP
#define SYSTEM_MONITOR_SENDER_GRAFANA_HPP

#include <grpcpp/grpcpp.h>

#include "sender/system_monitor_sender_grafana_inteface.hpp"

class SystemMonitorSenderGrafana : public ISystemMonitorSenderGrafana {
 public:
  SystemMonitorSenderGrafana();
  ~SystemMonitorSenderGrafana();

  bool init();
  bool start();
  bool stop();

  grpc::Status GetCpuUsage(grpc::ServerContext* context,
                           const systemmonitor::CpuUsageRequest* request,
                           systemmonitor::CpuUsageResponse* response) override;

 private:
  std::unique_ptr<grpc::Server> server_;
  std::string server_address_;
  std::shared_ptr<SystemMonitorSenderGrafana> shared_this_;
};

#endif  // SYSTEM_MONITOR_SENDER_GRAFANA_HPP