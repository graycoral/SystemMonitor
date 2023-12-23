
#include "system_monitor.hpp"

SystemMonitor::SystemMonitor() : reader_(nullptr), sender_(nullptr) {
  sender_ = std::make_unique<SystemMonitorSender>();
  reader_ = std::make_unique<SystemMonitorDataReaderBase>(sender_);
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
  if (reader_->start()) {
    std::cerr << "Failed to start system monitor reader." << std::endl;
    return false;
  }

  if (sender_->start()) {
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