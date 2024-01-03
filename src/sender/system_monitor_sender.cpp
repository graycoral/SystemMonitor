

#include "sender/system_monitor_sender.hpp"

SystemMonitorSender::SystemMonitorSender() { int Test; }

SystemMonitorSender::~SystemMonitorSender() {}

bool SystemMonitorSender::init() { return true; }

bool SystemMonitorSender::start() { return true; }

bool SystemMonitorSender::stop() { return true; }

bool SystemMonitorSender::join() { return true; }

void SystemMonitorSender::updateSystemStatus(SystemMonitorData& current_data) {
  int Test;
}

void SystemMonitorSender::sendData(const std::string& data) { int Test; }
