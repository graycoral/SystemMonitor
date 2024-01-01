#ifndef SYSTEM_MONITOR_DATA_READER_SAMSUNG_HPP
#define SYSTEM_MONITOR_DATA_READER_SAMSUNG_HPP

/**
 * @file system_monitor_dada_reader_samsung.hpp
 * @brief Header file for the SystemMonitorDataReaderSamsung class.
 *
 * This file contains the declaration of the SystemMonitorDataReaderSamsung
 * class, which is responsible for reading system monitor data specifically for
 * Samsung devices.
 */

class SystemMonitorDataReaderSamsung {
 private:
  /* data */
 public:
  SystemMonitorDataReaderSamsung();
  ~SystemMonitorDataReaderSamsung() = default;

  bool init();
  bool start();
  bool stop();
  bool join();
};

#endif // SYSTEM_MONITOR_DATA_READER_SAMSUNG_HPP