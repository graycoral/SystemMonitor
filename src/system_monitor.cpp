
#include "system_monitor.hpp"

SystemMonitor::SystemMonitor() {
  sender_ = std::make_shared<SystemMonitorSender>();
  std::weak_ptr<ISystemMonitorSender> weak_sender = sender_;  // 암시적 변환
  reader_ = std::make_shared<SystemMonitorReader>(weak_sender);
}

bool SystemMonitor::init() {
  if (!reader_->init()) {
    std::cerr << "Failed to initialize system monitor reader." << std::endl;
    return false;
  }

  if (!sender_->init()) {
    std::cerr << "Failed to initialize system monitor sender." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitor::start() {
  if (!reader_->start()) {
    std::cerr << "Failed to start system monitor reader." << std::endl;
    return false;
  }

  if (!sender_->start()) {
    std::cerr << "Failed to start system monitor sender." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitor::stop() {
  if (!reader_->stop()) {
    std::cerr << "Failed to stop system monitor reader." << std::endl;
    return false;
  }

  if (!sender_->stop()) {
    std::cerr << "Failed to stop system monitor sender." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitor::join() {
  if (!reader_->join()) {
    std::cerr << "Failed to join system monitor reader." << std::endl;
    return false;
  }

  if (!sender_->join()) {
    std::cerr << "Failed to join system monitor sender." << std::endl;
    return false;
  }

  return true;
}