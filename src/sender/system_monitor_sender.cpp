#include "sender/system_monitor_sender.hpp"

SystemMonitorSender::SystemMonitorSender() : current_data_() {
  std::cout << __func__ << std::endl;
  current_data_.cpu_usage.push_back(0);
  current_data_.cpu_temperature.push_back(0);
  current_data_.gpu_usage.push_back(0);
}

SystemMonitorSender::~SystemMonitorSender() {}

bool SystemMonitorSender::init() { return true; }

bool SystemMonitorSender::start() {
  std::cout << __func__ << std::endl;

  thread_ = std::thread([&] {
    while (true) {
      std::scoped_lock<std::mutex> lock(mutex_);
      sendData(current_data_);
      std::this_thread::sleep_for(std::chrono::milliseconds(kDefaultSleepTime));
    }
  });

  return true;
}

bool SystemMonitorSender::stop() { return true; }

bool SystemMonitorSender::join() {
  if (thread_.joinable()) {
    thread_.join();
    return false;
  }
  std::cout << "Sender thread Join" << std::endl;
  return true;
}

void SystemMonitorSender::updateSystemStatus(SystemMonitorData& current_data) {
  std::cout << __func__ << std::endl;
  std::scoped_lock<std::mutex> lock(mutex_);
  current_data_ = current_data;
}

void SystemMonitorSender::sendData(const SystemMonitorData& current_data) {
  debugSystemInfo(current_data);
  // TBD : Send Data to Node and grfana
}

void SystemMonitorSender::debugSystemInfo(
    const SystemMonitorData& current_data) {
  // TBD : Adjust for your system
  std::cout << "====== Debug System Info ======" << std::endl;
  std::cout << "CPU[0]: " << current_data.cpu_usage[0] << std::endl;
  std::cout << "Temperature[0]: " << current_data.cpu_temperature[0]
            << std::endl;
}
