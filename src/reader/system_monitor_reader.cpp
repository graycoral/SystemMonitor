#include "reader/system_monitor_reader.hpp"

#include "reader/system_monitor_data_reader_linux.hpp"

SystemMonitorReader::SystemMonitorReader(
    std::weak_ptr<ISystemMonitorSender>& system_iterface) {
  system_interface_ = system_iterface;
}

bool SystemMonitorReader::init() {
  data_reader_ = std::make_shared<SystemMonitorDataReaderLinux>();

  if (!data_reader_->init()) {
    std::cerr << "Failed to initialize system monitor reader." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitorReader::start() {
  thread_ = std::thread([&] {
    data_reader_->start();
    while (true) {
      SystemMonitorData cur_data{};

      if (data_reader_->readSystemInformation(cur_data)) {
        auto it = system_interface_.lock();
        if (it) {
          std::cout << "Update Data" << std::endl;
          it->updateSystemStatus(cur_data);
        }
      }
      prev_data_ = cur_data;
      std::this_thread::sleep_for(std::chrono::milliseconds(kDefaultSleepTime));
    }
  });

  return true;
}

bool SystemMonitorReader::stop() {
  if (!data_reader_->stop()) {
    std::cerr << "Failed to stop system monitor reader." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitorReader::join() {
  if (thread_.joinable()) {
    thread_.join();
    return false;
  }

  return true;
}
