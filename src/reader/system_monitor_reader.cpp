#include "reader/system_monitor_reader.hpp"

SystemMonitorReader::SystemMonitorReader(ISystemMonitorSender& system_info)
    : data_reader_(nullptr), system_info_(nullptr) {
#ifdef __linux__
  data_reader_ = std::make_unique<SystemMonitorDataReaderLinux>();
#else
  data_reader_ = std::make_unique<SystemMonitorDataReaderSamsung>();
#else
#endif  // __linux__
  data_rdaer system_info_ = system_info;
  prev_data_{};
}

SystemMonitorReader::~SystemMonitorReader() {
  data_reader_.reset();
  system_info_.reset();
}

bool SystemMonitorReader::init() {
  if (!data_reader_->init()) {
    std::cerr << "Failed to initialize system monitor reader." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitorReader::start() {
  if (data_reader_ != nullptr) {
    data_reader_->start();
  } else {
    return false;
  }

  if (system_info_ != nullptr) {
    system_info_->start();
  } else {
    return false;
  }

  return true;
}

bool SystemMonitorReader::stop() {
  if (data_reader_ != nullptr) {
    data_reader_->stop();
  } else {
    return false;
  }

  if (system_info_ != nullptr) {
    system_info_->stop();
  } else {
    return false;
  }

  return true;
}
