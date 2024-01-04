#include "sender/system_monitor_sender.hpp"

SystemMonitorSender::SystemMonitorSender() { int Test; }

SystemMonitorSender::~SystemMonitorSender() {}

bool SystemMonitorSender::init() { return true; }

bool SystemMonitorSender::start() {
  std::thread thread_ = std::thread([&] {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Sender Thread ID: " << this_id << std::endl;

    while (true) {
      std::cout << "Send Data" << std::endl;
      {
        std::scoped_lock<std::mutex> lock(mutex_);

        sendData(current_data_);
      }

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
  std::scoped_lock<std::mutex> lock(mutex_);
  current_data_ = current_data;
}

void SystemMonitorSender::sendData(const SystemMonitorData& current_data) {
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
