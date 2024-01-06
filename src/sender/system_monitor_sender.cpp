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
      std::cout << "Sender Thread" << std::endl;
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
  std::cout << __func__ << std::endl;
  debugSystemInfo(current_data);
}

void SystemMonitorSender::debugSystemInfo(
    const SystemMonitorData& current_data) {
  std::cout << "====== Debug System Info ======" << std::endl;
  std::cout << "CPU Usage: " << current_data.cpu_usage[0] << std::endl;
  std::cout << "CPU Temperature: " << current_data.cpu_temperature[0]
            << std::endl;
  std::cout << "GPU Usage: " << current_data.gpu_usage[0] << std::endl;

  // std::cout << "GPU Temperature: " << current_data.gpu_temperature <<
  // std::endl; std::cout << "GPU Memory Usage: " <<
  // current_data.gpu_memory_usage << std::endl; std::cout << "GPU Memory Total:
  // " << current_data.gpu_memory_total << std::endl;
}
