#include "reader/system_monitor_reader.hpp"

#include "common/system_monitor_common.hpp"

#ifdef __linux__
#include "reader/system_monitor_data_reader_linux.hpp"
#else
#include "reader/system_monitor_data_reader_samsung.hpp"
#endif

SystemMonitorReader::SystemMonitorReader(
    std::weak_ptr<ISystemMonitorSender>& system_info)
{
  system_interface_ = system_info;
}

bool SystemMonitorReader::init()
{
#ifdef __linux__
  data_reader_ = std::make_shared<SystemMonitorDataReaderLinux>();
#else
//   data_reader_ = std::make_shared<SystemMonitorDataReaderSamsung>();
#endif  // __linux__

  if (!data_reader_->init()) {
    std::cerr << "Failed to initialize system monitor reader." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitorReader::start()
{
    thread_ = std::thread([&] {
        data_reader_->start();
        while(true) {
            SystemMonitorData cur_data {};

            if(data_reader_->readSystemInformation()) {
                std::cout << "Update Data" << std::endl;
            }
            prev_data_ = cur_data;
        }
    });

  return true;
}

bool SystemMonitorReader::stop()
{
  if (!data_reader_->stop()) {
    std::cerr << "Failed to stop system monitor reader." << std::endl;
    return false;
  }

  return true;
}

bool SystemMonitorReader::join()
{
  if (thread_.joinable()) {
    thread_.join();
    return false;
  }

  return true;
}
